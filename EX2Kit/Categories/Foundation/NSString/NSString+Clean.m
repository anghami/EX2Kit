//
//  NSString+Clean.m
//  EX2Kit
//
//  Created by Ben Baron on 2/27/12.
//  Copyright (c) 2012 Anghami. All rights reserved.
//

#import "NSString+Clean.h"
#import "GTMNSString+HTML.h"

@implementation NSString (Clean)

- (NSString *)cleanString
{
	NSString *clean = [self gtm_stringByUnescapingFromHTML];
    if (clean) {
		NSString * escaped = [clean stringByRemovingPercentEncoding];
        if (escaped) {
            clean = escaped;
        }
    }
	
	return clean ? clean : self;
	//return [[self gtm_stringByUnescapingFromHTML] stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
}

- (NSString *)trimString
{
    return [self stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
}

@end
