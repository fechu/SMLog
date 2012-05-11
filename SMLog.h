/**
 @file SMLog.h

 @author Sandro Meier <sandro.meier@fidelisfactory.ch>
 @date 02.02.2012 
*/



/**
 Define here if you want to use the Macros or the class.  
 */
#define USE_LOGGING_MACROS  1

/**
 Define if you want to use the SMLOGGER class. 
 */
#define USE_SMLOGGER        1

/**
 If this options is set to 1, Line number and funtion name are added to the log.
 This option takes only affect if you use the macros. 
*/
#define ADD_INFORMATION 0



#if USE_LOGGING_MACROS 

    /** The lowest level. Usually used for debugging while developing. */
    #define LEVEL_DEBUG     @"DEBUG"
    /** Information you want to log but are more than for debugging purposes. */
    #define LEVEL_NOTICE    @"NOTICE"
    /** Logs information about warnings*/
    #define LEVEL_WARNING   @"WARNING"
    /** Logs important messages */
    #define LEVEL_IMPORTANT @"IMPORTANT"
    /** Logs very important information about errors. */
    #define LEVEL_ERROR     @"ERROR"

    /** 
     The UILog is always avaliable it shows a UIAlertView with the logging message.
     */
    #define UILog(fmt, ...) {UIAlertView *alert = [[UIAlertView alloc] initWithTitle:[NSString stringWithFormat:@"%s\n [Line %d] ", __PRETTY_FUNCTION__, __LINE__] message:[NSString stringWithFormat:fmt, ##__VA_ARGS__]  delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil]; [alert show]; }

    // Logs only in DEBUG mode.
    #ifdef DEBUG
        #if ADD_INFORMATION 
            #define DLog(level ,fmt, ...) NSLog((@"[%@]  %s [Line %d] " fmt), level, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
        #else
            #define DLog(level ,fmt, ...) NSLog((@"[%@]  " fmt), level, ##__VA_ARGS__);
        #endif
    #else
        #define DLog(...)
    #endif

    // ALog always displays output regardless of the DEBUG setting
    #define ALog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);

#endif



#if USE_SMLOGGER

#import <Foundation/Foundation.h>

/**
 The different Logging Levels
 */
enum {
    SMLogLevelDebug     = 1 << 0,
    SMLogLevelNotice    = 1 << 1,
    SMLogLevelWarning   = 1 << 2,
    SMLogLevelImportant = 1 << 3,
    SMLogLevelError     = 1 << 4
};
/**
 The typedefinition for the log levels. 
 */
typedef int SMLogLevel;

/**
 The class for easy logging.
 */
@interface SMLogger : NSObject

/**
 Contains all logged levels. The default is set to all levels. 
 */
@property(nonatomic, assign) SMLogLevel logLevels; 

/**
 Returns the shared logger. 
 You do not have to use this singleton. You can also instantiate your own instance
 and use that one. 
 @return The singleton instance.
 */
+ (SMLogger *)sharedLogger;

/**
 Logs text the text. 
 @param text The text
 @param level The level you want to log the text with. 
 */
+ (void)log:(NSString *)text level:(SMLogLevel)level;
/** @see SMLogger::log:level: */
- (void)log:(NSString *)text level:(SMLogLevel)level;

/**
 Logs to the sharedLogger with the level SMLogLevelDebug.
 */
+ (void)logDebug:(NSString *)text;
/** @see SMLogger::logDebug: */
- (void)logDebug:(NSString *)text;

/**
 Logs to the sharedLogger with the level SMLogLevelNotice.
 */
+ (void)logNotice:(NSString *)text;
/** @see SMLogger::logNotice: */
- (void)logNotice:(NSString *)text;

/**
 Logs to the sharedLogger with the level SMLogLevelWarning.
 */
+ (void)logWarning:(NSString *)text;
/** @see SMLogger::logWarning: */
- (void)logWarning:(NSString *)text;

/**
 Logs to the sharedLogger with the level SMLogLevelImportant.
 */
+ (void)logImportant:(NSString *)text;
/** @see SMLogger::logImportant: */
- (void)logImportant:(NSString *)text;

/**
 Logs to the sharedLogger with the level SMLogLevelError.
 */
+ (void)logError:(NSString *)text;
/** @see SMLogger::logError: */
- (void)logError:(NSString *)text;

@end

#endif