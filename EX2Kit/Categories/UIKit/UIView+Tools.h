//
//  UIView+Tools.h
//  EX2Kit
//
//  Created by Ben Baron on 12/22/10.
//  Copyright 2010 Ben Baron. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

#define BOTTOM_LINE_VIEW_TAG        1290831
#define TOP_LINE_VIEW_TAG           1319391

@interface UIView (Tools) 

@property (nonatomic) CGFloat left;
@property (nonatomic) CGFloat top;
@property (nonatomic) CGFloat right;
@property (nonatomic) CGFloat bottom;

@property (nonatomic) CGFloat x;
@property (nonatomic) CGFloat y;
@property (nonatomic) CGPoint origin;

@property (nonatomic) CGFloat width;
@property (nonatomic) CGFloat height;
@property (nonatomic) CGSize size;

@property (nonatomic, readonly) UIViewController *viewController;

#ifdef TVOS
#else
- (CGSize)realSizeDidRotate;
- (CGSize)realSizeDidRotate:(UIDeviceOrientation)currentOrientation;
+ (UIInterfaceOrientation)interfaceOrientationFromDeviceOrientation:(UIDeviceOrientation)deviceOrientation;
#endif

- (void)addLeftShadowWithWidth:(CGFloat)shadowWidth alpha:(CGFloat)shadowAlpha;
- (void)addLeftShadow;
- (void)removeLeftShadow;

- (void)addRightShadowWithWidth:(CGFloat)shadowWidth alpha:(CGFloat)shadowAlpha;
- (void)addRightShadow;
- (void)removeRightShadow;
+ (CAGradientLayer *)verticalShadowWithAlpha:(CGFloat)shadowAlpha inverse:(BOOL)inverse;

- (void)addBottomShadowWithWidth:(CGFloat)shadowWidth alpha:(CGFloat)shadowAlpha;
- (void)addBottomShadow;
- (void)removeBottomShadow;

- (CGPoint)centerOfBounds;

- (void)addTopShadowWithWidth:(CGFloat)shadowWidth alpha:(CGFloat)shadowAlpha;
- (void)addTopShadow;
- (void)removeTopShadow;
+ (CAGradientLayer *)horizontalShadowWithAlpha:(CGFloat)shadowAlpha inverse:(BOOL)inverse;

- (UIView *) bottomLine;
- (void)addBottomLine;
- (void) removeBottomLine;

- (UIView *) topLine;
- (void)addTopLine;
- (void) removeTopLine;

// Convert view from left to right to right to left layout for switching to Arabic/Hebrew
- (void)convertToRTL;

- (BOOL)isChildOfView:(UIView *)aView;
- (BOOL)isChildOfViewType:(Class)aClass;

- (void)centerHorizontally;
- (void)centerVertically;
- (void)centerHorizontallyAndVertically;

- (void)centerHorizontallyInBounds:(CGRect)bounds;
- (void)centerVerticallyInBounds:(CGRect)bounds;
- (void)centerHorizontallyAndVerticallyInBounds:(CGRect)bounds;

@end
