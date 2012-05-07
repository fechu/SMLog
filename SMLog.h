//
//  SMLog.h
//
//  Created by Sandro Meier on 02.02.2012.
//  Copyright 2011 Fidelis Factory. All rights reserved.
//

/* 
 The different Logging Levels for DLog
 
 Use DLog\(.*\) to find all Logs and replace with DLog\(LEVEL_DEBUG, \1\)
 */
#define LEVEL_DEBUG     @"DEBUG"
#define LEVEL_NOTICE    @"NOTICE"
#define LEVEL_WARNING   @"WARNING"
#define LEVEL_IMPORTANT @"IMPORTANT"
#define LEVEL_ERROR     @"ERROR"

// If this options is set to 1, Line number and funtion name are added to the log.  
#define ADD_INFORMATION 0

// Logs only in DEBUG mode.
#ifdef DEBUG
#   if ADD_INFORMATION 
#       define DLog(level ,fmt, ...) NSLog((@"[%@]  %s [Line %d] " fmt), level, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#   else
#       define DLog(level ,fmt, ...) NSLog((@"[%@]  " fmt), level, ##__VA_ARGS__);
#   endif
#else
#   define DLog(...)
#endif

// ALog always displays output regardless of the DEBUG setting
#define ALog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);

// Shows a UIAlertView with the logged Data. 
#define UILog(fmt, ...) {UIAlertView *alert = [[UIAlertView alloc] initWithTitle:[NSString stringWithFormat:@"%s\n [Line %d] ", __PRETTY_FUNCTION__, __LINE__] message:[NSString stringWithFormat:fmt, ##__VA_ARGS__]  delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil]; [alert show]; }