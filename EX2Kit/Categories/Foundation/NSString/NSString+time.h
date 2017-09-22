//
//  NSString-time.h
//  EX2Kit
//
//  Created by Benjamin Baron on 10/30/11.
//  Copyright (c) 2011 Ben Baron. All rights reserved.
//

@interface NSString (time)

+ (NSString *)formatTime:(double)seconds;
+ (NSString *)formatTimeDecimalHours:(double)seconds;
+ (NSString *)relativeTime:(NSDate *)date;
+ (NSString *)shortRelativeDateFromDate:(NSDate *)date;

+ (NSString *)formatTimeHoursMinutes:(double)seconds hideHoursIfZero:(BOOL)hideHoursIfZero NS_SWIFT_NAME(init(seconds:hideHoursIfZero:));

@end
