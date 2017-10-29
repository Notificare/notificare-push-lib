//
//  Passbook.m
//  NotificarePushLib
//
//  Created by Joel Oliveira on 1/24/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import "NotificarePassbook.h"
#import "NSString+Utils.h"

@implementation NotificarePassbook


- (id)init {
    
    self = [super init];
    
    if (self){

         [self setRootViewController:[[[UIApplication sharedApplication] keyWindow] rootViewController]];
        
        if ([[[self rootViewController] presentedViewController] isKindOfClass:[UIViewController class]]) {
            [self setOriginalView:[[self rootViewController] presentedViewController]];
        }
        
        

        [self setPassLib:[[PKPassLibrary alloc] init]];

        [self setViewController:[[UIViewController alloc] init]];
        [self setNavigationController:[[UINavigationController alloc] initWithRootViewController:[self viewController]]];
        
        
        [self setWebView:[[UIWebView alloc] initWithFrame:CGRectMake(0, 0, self.viewController.view.frame.size.width, self.viewController.view.bounds.size.height)]];

        [[self webView] setDelegate:self];
        
        NSString *plistPath = [[NSBundle mainBundle] pathForResource:@"Notificare" ofType:@"plist"];
        NSDictionary *pfile = [NSDictionary dictionaryWithContentsOfFile:plistPath];
        
        
        [[UIBarButtonItem appearanceWhenContainedIn:[[[self navigationController] navigationBar] class], nil] setTintColor:[self colorWithHexString:[[pfile objectForKey:@"OPTIONS"] objectForKey:@"BUTTONS_TEXT_COLOR"]]];
        
        
        NSShadow *shadow = [NSShadow new];
        [shadow setShadowColor:[UIColor clearColor]];
        [shadow setShadowOffset:CGSizeMake(-1.0, 0.0)];
        
        NSDictionary *navbarTitleTextAttributes = [NSDictionary dictionaryWithObjectsAndKeys:
                                                   [self colorWithHexString:[[pfile objectForKey:@"OPTIONS"] objectForKey:@"TITLE_COLOR"]], NSForegroundColorAttributeName,
                                                   shadow, NSShadowAttributeName, nil];
        
        NSDictionary *barbuttonTitleTextAttributes = [NSDictionary dictionaryWithObjectsAndKeys:
                                                      [self colorWithHexString:[[pfile objectForKey:@"OPTIONS"] objectForKey:@"BUTTONS_TEXT_COLOR"]], NSForegroundColorAttributeName,
                                                      shadow, NSShadowAttributeName, nil];
        
        
        
        [[UIBarButtonItem appearance] setTitleTextAttributes:barbuttonTitleTextAttributes forState:UIControlStateNormal];
        [[UIBarButtonItem appearance] setTitleTextAttributes:barbuttonTitleTextAttributes forState:UIControlStateDisabled];
        [[UIBarButtonItem appearance] setTitleTextAttributes:barbuttonTitleTextAttributes forState:UIControlStateHighlighted];
        
        
        [[UINavigationBar appearance] setTitleTextAttributes:navbarTitleTextAttributes];
        
        
        if([UIImage imageFromBundle:@"closeIcon"]){
            [self setCloseButton:[[UIBarButtonItem alloc]
                                  initWithImage:[UIImage imageFromBundle:@"closeIcon"]
                                  style:UIBarButtonItemStylePlain
                                  target:self
                                  action:@selector(openActions)]];
            
        }else{
            [self setCloseButton:[[UIBarButtonItem alloc]
                                  initWithTitle:([NSString stringFromBundle:@"close"])?[NSString stringFromBundle:@"close"]:@"close"
                                  style:UIBarButtonItemStylePlain
                                  target:self
                                  action:@selector(openActions)]];
        }
        
        
        [[self closeButton] setTintColor:[self colorWithHexString:[[pfile objectForKey:@"OPTIONS"] objectForKey:@"BUTTONS_TEXT_COLOR"]]];
        
        
        [[[[self viewController] navigationController] navigationBar] setBarTintColor:[self colorWithHexString:[[pfile objectForKey:@"OPTIONS"] objectForKey:@"NAVBAR_COLOR"]]];
        
        
    }
    
    
    return self;
}


-(UIColor*)colorWithHexString:(NSString*)hex
{
    NSString *cString = [[hex stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] uppercaseString];
    
    // String should be 6 or 8 characters
    if ([cString length] < 6) return [UIColor grayColor];
    
    // strip 0X if it appears
    if ([cString hasPrefix:@"0X"]) cString = [cString substringFromIndex:2];
    
    if ([cString length] != 6) return  [UIColor grayColor];
    
    // Separate into r, g, b substrings
    NSRange range;
    range.location = 0;
    range.length = 2;
    NSString *rString = [cString substringWithRange:range];
    
    range.location = 2;
    NSString *gString = [cString substringWithRange:range];
    
    range.location = 4;
    NSString *bString = [cString substringWithRange:range];
    
    // Scan values
    unsigned int r, g, b;
    [[NSScanner scannerWithString:rString] scanHexInt:&r];
    [[NSScanner scannerWithString:gString] scanHexInt:&g];
    [[NSScanner scannerWithString:bString] scanHexInt:&b];
    
    return [UIColor colorWithRed:((float) r / 255.0f)
                           green:((float) g / 255.0f)
                            blue:((float) b / 255.0f)
                           alpha:1.0f];
}


-(void)openNotification{
    
    if (_rootViewController){
        
        
        if ([PKPassLibrary isPassLibraryAvailable]){
            
            
            for (NotificareContent * content in [[self notification] notificationContent]) {
                
                NSURL *passbookUrl = [NSURL URLWithString:[content data]];
                NSData *data = [[NSData alloc] initWithContentsOfURL:passbookUrl];
                NSError *error;
                
                //init a pass object with the data
                [self setPass:[[PKPass alloc] initWithData:data error:&error]];
                
                if(error){
                    NSLog(@"Notificare: Could not open pass");
                    [_delegate notificationType:self didFailToOpenNotification:[self notification]];
                } else {
                    
                    //present view controller to add the pass to the library
                    PKAddPassesViewController * vc = [[PKAddPassesViewController alloc] initWithPass:[self pass]];
                    
                    [vc setDelegate:self];
                    
                    if (![[self rootViewController] presentedViewController]) {
                        
                        [_rootViewController presentViewController:vc animated:YES completion:^(void){
                            
                            [_delegate notificationType:self didOpenNotification:[self notification]];
                            
                        }];
                        
                    } else {
                        
                        [[self rootViewController] dismissViewControllerAnimated:NO completion:^{
                            
                            [_rootViewController presentViewController:vc animated:YES completion:^(void){
                                
                                [_delegate notificationType:self didOpenNotification:[self notification]];
                                
                            }];
                            
                        }];
                        
                    }
                    
                }
                
                
                break;
            }
            
        } else {
            
            [[[self viewController] navigationItem] setLeftBarButtonItem:[self closeButton]];
            
            
            if([UIImage imageFromBundle:@"logoTitle"]){
                UIView * iv = [[UIView alloc] initWithFrame:CGRectMake(0,0,[UIImage imageFromBundle:@"logoTitle"].size.width, [UIImage imageFromBundle:@"logoTitle"].size.height)];
                [iv addSubview:[[UIImageView alloc] initWithImage:[UIImage imageFromBundle:@"logoTitle"]]];
                [[[self viewController] navigationItem] setTitleView:iv];
                
            } else {
                [[self viewController] setTitle:[NSString appName]];
            }
            
            
            if ([[self notification] notificationContent] &&
                [[[self notification] notificationContent] count] > 0 &&
                [[[self notification] notificationContent] firstObject]) {
                
                NotificareContent * content = (NotificareContent*)[[[self notification] notificationContent] firstObject];
                
                NSString * serial = [[content data] stringByReplacingOccurrencesOfString:@"https://push.notifica.re/pass/pkpass/" withString:@""];
                
                NSURL *passbookUrl = [NSURL URLWithString:[NSString stringWithFormat:@"https://push.notifica.re/pass/forapplication/%@/%@", [[[self notification] application] objectForKey:@"_id"], serial]];
                
                
                NSURLRequest *nsRequest=[NSURLRequest requestWithURL:passbookUrl];
                [[self webView] loadRequest:nsRequest];
                
                [[self viewController] setView:[self webView]];
                
                
                if (![[self rootViewController] presentedViewController]) {
                    
                    [_rootViewController presentViewController:[self navigationController] animated:YES completion:^(void){
                        
                        [_delegate notificationType:self didOpenNotification:[self notification]];
                        
                    }];
                    
                } else {
                    
                    [[self rootViewController] dismissViewControllerAnimated:NO completion:^{
                        
                        [_rootViewController presentViewController:[self navigationController] animated:YES completion:^(void){
                            
                            [_delegate notificationType:self didOpenNotification:[self notification]];
                            
                        }];
                        
                    }];
                    
                }
                
            } else {
                
                NSLog(@"Notificare: PKPassLibrary is not available");
                [_delegate notificationType:self didFailToOpenNotification:[self notification]];
                
            }
            
        }
        
        
        
    }else{
        NSLog(@"Notificare: No Root View Controller");
        [_delegate notificationType:self didFailToOpenNotification:[self notification]];
    }
    
}

-(void)addPassesViewControllerDidFinish:(PKAddPassesViewController *)controller{
    
    
    if([[self passLib] containsPass:[self pass]]){
        NSMutableDictionary* action = [NSMutableDictionary dictionary];
        [action setValue:[[self notification] notificationID] forKey:@"notification"];
        [action setValue:@"Added pkpass to Passbook" forKey:@"label"];
        [_delegate notificationType:self log:action];
        
    }
    [controller dismissViewControllerAnimated:YES completion:^{
        [_delegate notificationType:self didCloseNotification:[self notification]];
        
        if ([self originalView]){
            
            [[self rootViewController] presentViewController:[self originalView] animated:YES completion:^(void){
                
            }];
        }
        
    }];
}


-(void)openActions{
    
    
    
    UIAlertController * alert=   [UIAlertController
                                  alertControllerWithTitle:[NSString appName]
                                  message:[[self notification] notificationMessage]
                                  preferredStyle:UIAlertControllerStyleActionSheet];
    
    
    UIAlertAction* cancel = [UIAlertAction
                             actionWithTitle:([NSString stringFromBundle:@"cancel"])?[NSString stringFromBundle:@"cancel"]:@"cancel"
                             style:UIAlertActionStyleCancel
                             handler:^(UIAlertAction * action)
                             {
                                 
                                 
                             }];
    [alert addAction:cancel];
    
    UIAlertAction* close = [UIAlertAction
                            actionWithTitle:([NSString stringFromBundle:@"close"])?[NSString stringFromBundle:@"close"]:@"close"
                            style:UIAlertActionStyleDestructive
                            handler:^(UIAlertAction * action)
                            {
                                [self closeModalWindow];
                                
                            }];
    [alert addAction:close];
    
    
    if ( UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad ) {
        
        [alert setModalPresentationStyle:UIModalPresentationPopover];
        UIPopoverPresentationController *popPresenter = [alert
                                                         popoverPresentationController];
        
         [popPresenter setBarButtonItem:[self closeButton]];
        
    } else {
        
        [alert setModalPresentationStyle:UIModalPresentationOverCurrentContext];
    }
    
    [[self navigationController] presentViewController:alert animated:YES completion:^{
        
    }];
    
    
}


-(void)webViewDidStartLoad:(UIWebView *)webView{

}

- (void)webViewDidFinishLoad:(UIWebView *)webView{
    
    //Let's remove the add button which does not apply in iPad
    [webView stringByEvaluatingJavaScriptFromString:@"$(\".add\").remove();"];
    
}

- (void)webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error
{
    NSLog(@"Notificare: Failed to open Pass Web Version");
    [_delegate notificationType:self didFailToOpenNotification:[self notification]];
    [self closeModalWindow];
    
}




-(void)closeModalWindow{

    [[self rootViewController] dismissViewControllerAnimated:NO completion:^{
        [_delegate notificationType:self didCloseNotification:[self notification]];
        
        if ([self originalView]){
            
            [[self rootViewController] presentViewController:[self originalView] animated:YES completion:^(void){
                
            }];
        }
        
    }];
}



-(void)sendData:(NSArray *)data{
}

@end
