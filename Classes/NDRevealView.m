//
//  NDRevealView.m
//  NDRevealView
//
//  Created by Nathan Day on 22/07/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "NDRevealView.h"

@interface NDRevealView ()
{
@private
	BOOL		expanded;
	UIView		* hideContent;
}

@end

@implementation NDRevealView

@synthesize		expanded,
				hideContent;

#pragma mark -
#pragma mark Manually implemented properties

- (void)setExpanded:(BOOL)anExpanded
{
	[self setExpanded:anExpanded animate:YES];
}

- (void)setExpanded:(BOOL)anExpanded animate:(BOOL)anAnimate
{
	if( anExpanded != expanded )
	{
		CGRect	theFrame = self.frame;
		if( anAnimate )
		{
			if( anExpanded )
			{
				theFrame.size.height += CGRectGetHeight(self.hideContent.frame);
				[UIView beginAnimations:@"animation2" context:NULL];
				[UIView setAnimationDuration:0.3];
				self.frame = theFrame;
				[UIView commitAnimations];
				
				self.hideContent.hidden = NO;
				[UIView beginAnimations:@"animation1" context:NULL];
				[UIView setAnimationDuration:0.3];
				[UIView setAnimationDelay:0.3];
				self.hideContent.alpha = 1.0;
				[UIView commitAnimations];
			}
			else
			{
				[UIView beginAnimations:@"animation1" context:NULL];
				[UIView setAnimationDuration:0.3];
				self.hideContent.alpha = 0.0;
				[UIView commitAnimations];
				
				theFrame.size.height -= CGRectGetHeight(self.hideContent.frame);
				[UIView beginAnimations:@"animation2" context:NULL];
				[UIView setAnimationDuration:0.3];
				[UIView setAnimationDelegate:self];
				[UIView setAnimationDidStopSelector:@selector(expandAnimationDidStop:finished:context:)];
				[UIView setAnimationDelay:0.1];
				self.frame = theFrame;
				[UIView commitAnimations];
			}
		}
		else
		{
			if( anExpanded )
			{
				theFrame.size.height += CGRectGetHeight(self.hideContent.frame);
				self.frame = theFrame;
				self.hideContent.hidden = NO;
				self.hideContent.alpha = 1.0;
			}
			else
			{
				self.hideContent.alpha = 0.0;
				theFrame.size.height -= CGRectGetHeight(self.hideContent.frame);
				self.frame = theFrame;
			}
			
		}
		expanded = anExpanded;
	}	
}
			 
- (void)expandAnimationDidStop:(NSString *)anAnimationID finished:(NSNumber *)aFinished context:(void *)aContext
{
	self.hideContent.hidden = !self.isExpanded;
}

#pragma mark - View lifecycle

- (void)awakeFromNib
{
	[super awakeFromNib];
	[self setExpanded:NO animate:NO]; 
}

#pragma mark - creation and destruction

- (id)initWithFrame:(CGRect)aFrame
{
    if( (self = [super initWithFrame:aFrame]) != nil )
        expanded = YES;
    return self;
}

- (id)initWithCoder:(NSCoder *)aDecoder
{
    if( (self = [super initWithCoder:aDecoder]) != nil )
        expanded = YES;
    return self;
}

#pragma mark - Actions
- (IBAction)toggleExpansion:(id)aSender { self.expanded = !self.isExpanded; }
- (IBAction)expansion:(id)aSender { self.expanded = YES; }
- (IBAction)compact:(id)aSender { self.expanded = NO; }

@end
