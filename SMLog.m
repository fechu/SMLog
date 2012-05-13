/**
 @file SMLog.m
 
 @author Sandro Meier <sandro.meier@fidelisfactory.ch>
 @date 10.5.2012
 */

#import "SMLog.h"

@interface SMLogger ()

/**
 Returns the name as a string for level.
 @param level The level you want the name for
 */
+ (NSString *)nameForLogLevel:(SMLogLevel)level;

@end





@implementation SMLogger

@synthesize logLevels;

/**
 The variable that contains the sharedLogger
 */
static SMLogger *aLogger;

#pragma mark - Initialization

- (id)init
{
    if (self = [super init])
    {
        self.logLevels = SMLogLevelDebug | SMLogLevelNotice | SMLogLevelWarning | SMLogLevelImportant | SMLogLevelError; 
    }
    
    return self;
}

+ (SMLogger *)sharedLogger
{
    if (aLogger == nil)
    {
        @synchronized(self) 
        {
            if (aLogger == nil)
            {
                // Create the shared logger
                aLogger = [[SMLogger alloc] init];
            }
        }
    }
    return aLogger;
}

#pragma mark - Generic Logging

+ (void)log:(NSString *)text level:(SMLogLevel)level
{
    [[SMLogger sharedLogger] log:text level:level];
}

- (void)log:(NSString *)text level:(SMLogLevel)level
{
    // Check if the given Level should be logged.
    if (logLevels & level) 
    {
        NSLog(@"%@ %@", [SMLogger nameForLogLevel:level], text);
    }
}

+ (void)logDebug:(NSString *)text, ...
{
    va_list args;
    va_start(args, text);
    [[SMLogger sharedLogger] logDebug:[[NSString alloc] initWithFormat:text arguments:args]];
}

- (void)logDebug:(NSString *)text
{
    [self log:text level:SMLogLevelDebug];
}

+ (void)logNotice:(NSString *)text, ...
{
    va_list args;
    va_start(args, text);
    [[SMLogger sharedLogger] logNotice:[[NSString alloc] initWithFormat:text arguments:args]];
}

- (void)logNotice:(NSString *)text
{
    [self log:text level:SMLogLevelNotice];
}

+ (void)logWarning:(NSString *)text, ...
{
    va_list args;
    va_start(args, text);
    [[SMLogger sharedLogger] logWarning:[[NSString alloc] initWithFormat:text arguments:args]];
}

- (void)logWarning:(NSString *)text
{
    [self log:text level:SMLogLevelWarning];
}

+ (void)logImportant:(NSString *)text, ...
{
    va_list args;
    va_start(args, text);
    [[SMLogger sharedLogger] logImportant:[[NSString alloc] initWithFormat:text arguments:args]];
}

- (void)logImportant:(NSString *)text
{
    [self log:text level:SMLogLevelImportant];
}

+ (void)logError:(NSString *)text, ...
{
    va_list args;
    va_start(args, text);
    [[SMLogger sharedLogger] logError:[[NSString alloc] initWithFormat:text arguments:args]];
}

- (void)logError:(NSString *)text
{
    [self log:text level:SMLogLevelError];
}

#pragma mark - Names

+ (NSString *)nameForLogLevel:(SMLogLevel)level 
{
    switch (level) {
        case SMLogLevelDebug:
        {
            return @"DEBUG    ";
            break;
        }   
        case SMLogLevelNotice:
        {
            return @"NOTICE   ";
            break;
        }
        case SMLogLevelWarning:
        {
            return @"WARNING  ";
            break;
        }
        case SMLogLevelImportant:
        {
            return @"IMPORTANT";
            break;
        }
        case SMLogLevelError:
        {
            return @"ERROR    ";
            break;
        }
        default:
            return @"";
            break;
    }
}

@end