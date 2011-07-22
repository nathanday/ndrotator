//
//  NDRevealView.h
//  NDRevealView
//
//  Created by Nathan Day on 22/07/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NDRevealView : UIView

@property (nonatomic, getter=isExpanded) BOOL	expanded;
@property (retain)			IBOutlet UIView		* hideContent;

- (IBAction)toggleExpansion:(id)sender;
- (IBAction)expansion:(id)sender;
- (IBAction)compact:(id)sender;

- (void)setExpanded:(BOOL)expanded animate:(BOOL)animate;

@end
