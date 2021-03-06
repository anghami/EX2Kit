//
//  EX2ActionQueue.h
//  EX2Kit
//
//  Created by Benjamin Baron on 5/23/13.
//
//

#import "EX2Action.h"

typedef enum
{
    EX2ActionQueueState_NotStarted,
    EX2ActionQueueState_Started,
    EX2ActionQueueState_Stopped,
    EX2ActionQueueState_Finished
} EX2ActionQueueState;

@class EX2ActionQueue;

@protocol EX2ActionQueueDelegate <NSObject>

- (void)actionQueue:(EX2ActionQueue *)queue stateChangedFrom:(EX2ActionQueueState)oldState to:(EX2ActionQueueState)newState;

@end

@interface EX2ActionQueue : NSObject

@property (readonly) EX2ActionQueueState queueState;

@property (readonly) NSArray *runningActions;
@property (readonly) NSArray *actions;
@property (readonly) NSUInteger actionCount;
@property (readonly) BOOL didFail;

@property (nonatomic, weak) id<EX2ActionQueueDelegate> delegate;

@property NSUInteger numberOfConcurrentActions;
@property NSTimeInterval delayBetweenActions;

- (BOOL)isActionInQueue:(id<EX2Action>)action;
- (BOOL)isActionOfTypeInQueue:(Class)type;

- (void)startQueue;
- (void)stopQueue:(BOOL)cancelRunningActions;
- (void)clearQueue;

- (void)queueAction:(id<EX2Action>)action;
- (BOOL)cancelAction:(id<EX2Action>)action; // Not all actions are cancelleable

// Action reporting
- (void)actionFailed:(id<EX2Action>)action;
- (void)actionFinished:(id<EX2Action>)action;

@end
