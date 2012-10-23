//
//  EX2NotificationBar.h
//
//  Created by Ben Baron on 4/17/12.
//  Copyright (c) 2012 Ben Baron. All rights reserved.
//

// If you use a UITabBarController, switch to using EX2TabBarController,
// and if you're using UINavigationController, use EX2NavigationController.
// There are a bunch of dirty hacks in here to support the UIKit classes,
// but they don't work nearly as well and not every edge case is covered.

#import <UIKit/UIKit.h>

#define EX2NotificationBarWillShow @"EX2NotificationBarWillShow"
#define EX2NotificationBarWillHide @"EX2NotificationBarWillHide"
#define EX2NotificationBarDidShow @"EX2NotificationBarDidShow"
#define EX2NotificationBarDidHide @"EX2NotificationBarDidHide"

typedef enum 
{
	EX2NotificationBarPositionTop,
	EX2NotificationBarPositionBottom
} 
EX2NotificationBarPosition;

@interface EX2NotificationBar : UIViewController

// View to place notification bar content. May add any custom subviews, etc. 
// Think of like UITableViewCell contentView.
#if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_0
@property (unsafe_unretained, nonatomic, readonly) IBOutlet UIView *notificationBarContent;
#else
@property (weak, nonatomic, readonly) IBOutlet UIView *notificationBarContent;
#endif

// The notification bar area. Contains the content view and shadows. Always add
// subviews to the content view, NOT to this view, or they will be placed
// above the shadows unless you specifically move them backwards in the hierarchy
#if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_0
@property (unsafe_unretained, nonatomic, readonly) IBOutlet UIView *notificationBar;
#else
@property (weak, nonatomic, readonly) IBOutlet UIView *notificationBar;
#endif

// The view that contains the main view. This is where you would add your UITabBarController,
// UINavigationController, etc.
#if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_0
@property (unsafe_unretained, nonatomic, readonly) IBOutlet UIView *mainViewHolder;
#else
@property (weak, nonatomic, readonly) IBOutlet UIView *mainViewHolder;
#endif

// YES when the notificationBar is visible
@property (nonatomic, readonly) BOOL isNotificationBarShowing;

// YES when the notificationBar is currently transitioning
@property (nonatomic, readonly) BOOL isNotificationBarAnimating;

// This can be changed during runtime, but only when isNotificationBarShowing == NO
@property EX2NotificationBarPosition position;

// This is a reference to whatever controller manages the view you placed in mainViewHolder
@property (nonatomic, strong) IBOutlet UIViewController *mainViewController;

// The height of the content area when shown
@property CGFloat notificationBarHeight;

- (id)initWithPosition:(EX2NotificationBarPosition)thePosition;

- (id)initWithPosition:(EX2NotificationBarPosition)thePosition mainViewController:(UIViewController *)mainViewController;


// Show the notificationBar temporarily, then automatically dismiss
- (void)showAndHideForDuration:(NSTimeInterval)duration;
- (void)showAndHide;

// Show the notificationBar indefinitely
- (void)show;
- (void)show:(void (^)(void))completionBlock;

// Hide the notificationBar
- (void)hide;
- (void)hide:(void (^)(void))completionBlock;

@end