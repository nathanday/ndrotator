//
//  StandardViewController.m
//  RotatingControllerView
//
//  Created by Nathan Day on 7/07/11.
//  Copyright 2011 Nathan Day. All rights reserved.
//

#import "StandardViewController.h"

static NSString			* const kNibName = @"StandardViewController";
static NSString		* const kThumbTintStr[] = { @"grey", @"red", @"green", @"blue", @"yellow", @"magenta", @"teal", @"orange", @"pink", @"lime", @"spring green", @"purple", @"aqua", @"black" };

@interface StandardViewController ()
- (void)setRotatorSize:(CGFloat)size;
- (void)updateOutputValueFields;
@end

@implementation StandardViewController
@synthesize nextThumbTintButton;
@synthesize		angleTextView,
				radiusTextView,
				xTextView,
				yTextView,
				valueTextView,
				rotatorView,
				styleControl,
				minimumDomainTextView,
				maximumDomainTextView,
				minimumRangeTextView,
				maximumRangeTextView,
				wrapConstrainButton,
				continuousButton;

/*
- (void)didReceiveMemoryWarning
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}
*/
#pragma mark - View lifecycle

- (void)viewDidLoad
{
	self.rotatorView.continuous = YES;
	self.rotatorView.wrapAround = YES;
	self.rotatorView.style = NDRotatorStyleRotate;
	[self updateOutputValueFields];
    [super viewDidLoad];
	self.title = @"Standard";
}

- (void)viewDidUnload
{
	self.angleTextView = nil;
	self.radiusTextView = nil;
    self.xTextView = nil;
    self.yTextView = nil;
    self.valueTextView = nil;
	self.styleControl = nil;
	self.wrapConstrainButton = nil;
	self.continuousButton = nil;
	self.rotatorView = nil;
	self.minimumDomainTextView = nil;
	self.maximumDomainTextView = nil;
	self.minimumRangeTextView = nil;
	self.maximumRangeTextView = nil;

	[self setNextThumbTintButton:nil];
    [super viewDidUnload];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

- (id)init { return [self initWithNibName:kNibName bundle:nil]; }

- (void)dealloc
{
	[angleTextView release];
	[radiusTextView release];
    [xTextView release];
    [yTextView release];
    [valueTextView release];
	[rotatorView release];
	[minimumDomainTextView release];
	[maximumDomainTextView release];
	[minimumRangeTextView release];
	[maximumRangeTextView release];
    [wrapConstrainButton release];
	[continuousButton release];
	[styleControl release];
	[nextThumbTintButton release];
	[super dealloc];
}

- (IBAction)changeMinimunDomainAction:(UITextField *)aSender
{
	NSParameterAssert( aSender == self.minimumDomainTextView );
	self.rotatorView.minimumDomain = self.minimumDomainTextView.text.floatValue * M_PI;
}

- (IBAction)changeMaximumDomainAction:(UITextField *)aSender
{
	NSParameterAssert( aSender == self.maximumDomainTextView );
	self.rotatorView.maximumDomain = self.maximumDomainTextView.text.floatValue * M_PI;
}

- (IBAction)changeMinimunRangeAction:(UITextField *)aSender
{
	NSParameterAssert( aSender == self.minimumRangeTextView );
	self.rotatorView.minimumValue = self.minimumRangeTextView.text.floatValue;
}

- (IBAction)changeMaximumRangeAction:(UITextField *)aSender
{
	NSParameterAssert( aSender == self.maximumRangeTextView );
	self.rotatorView.maximumValue = self.maximumRangeTextView.text.floatValue;
}

- (IBAction)changeStyleAction:(UISegmentedControl *)aSender
{
	switch( aSender.selectedSegmentIndex )
	{
	case 0:
		self.rotatorView.style = NDRotatorStyleDisc;
		break;
	case 1:
		self.rotatorView.style = NDRotatorStyleRotate;
		break;
		case 2:
		self.rotatorView.style = NDRotatorStyleLinear;
		break;
	default:
		break;
	}
}

- (IBAction)changeSizeAction:(UISlider *)aSender
{
	[self setRotatorSize:aSender.value];
	[self.rotatorView setNeedsDisplay];
}

- (IBAction)changeWrapConstrainAction:(id)aSender
{
	self.rotatorView.wrapAround = self.rotatorView.wrapAround ? NO : YES;
	self.wrapConstrainButton.selected = self.rotatorView.wrapAround;
	[self.wrapConstrainButton setNeedsDisplay];
}

- (IBAction)changeContinuousAction:(id)aSender
{
	self.rotatorView.continuous = self.rotatorView.isContinuous ? NO : YES;
	self.continuousButton.selected = self.rotatorView.isContinuous;
	[self.continuousButton setNeedsDisplay];
}

- (IBAction)nextThumbTintAction:(id)aSender
{
	NSUInteger	theTint = self.rotatorView.thumbTint;
	theTint++;
	if( theTint > NDThumbTintBlack )
		theTint = NDThumbTintGrey;

	self.nextThumbTintButton.selected = NO;
	self.nextThumbTintButton.highlighted = NO;
	[self.nextThumbTintButton setTitle:kThumbTintStr[theTint] forState:UIControlStateNormal];
	self.rotatorView.thumbTint = (enum NDThumbTint)theTint;
	[self.nextThumbTintButton setNeedsDisplay];
	[self.rotatorView setNeedsDisplay];
}

- (IBAction)changeRotatorAction:(NDRotator *)aSender
{
	NSParameterAssert( aSender == self.rotatorView );
	self.angleTextView.text = [NSString stringWithFormat:@"%.2f", self.rotatorView.angle/M_PI];
	[self.angleTextView setNeedsDisplay];
	self.radiusTextView.text = [NSString stringWithFormat:@"%.2f", self.rotatorView.radius];
	[self.radiusTextView setNeedsDisplay];
	self.xTextView.text = [NSString stringWithFormat:@"%.2f", self.rotatorView.cartesianPoint.x];
	[self.xTextView setNeedsDisplay];
	self.yTextView.text = [NSString stringWithFormat:@"%.2f", self.rotatorView.cartesianPoint.y];
	[self.yTextView setNeedsDisplay];
	self.valueTextView.text = [NSString stringWithFormat:@"%.2f", self.rotatorView.value];
	[self.valueTextView setNeedsDisplay];
}
#pragma mark -
#pragma mark UITextFieldDelegate methods

- (BOOL)textFieldShouldReturn:(UITextField *)aTextField
{
	[aTextField resignFirstResponder];
	return YES;
}

- (BOOL)textFieldShouldClear:(UITextField *)aTextField
{
	return YES;
}

#pragma mark -
#pragma mark Private Methods

- (void)setRotatorSize:(CGFloat)aSize
{
	CGRect		theRect = self.rotatorView.frame;
	CGPoint		theFixedPoint = CGPointMake(CGRectGetMidX(theRect), CGRectGetMidY(theRect) );
	theRect.size.width = aSize;
	theRect.size.height = aSize;
	theRect.origin.x = theFixedPoint.x - aSize/2.0;
	theRect.origin.y = theFixedPoint.y - aSize/2.0;
	self.rotatorView.frame = theRect;
}

- (void)updateOutputValueFields
{
	self.angleTextView.text = [NSString stringWithFormat:@"%.2f", self.rotatorView.angle/M_PI];
	[self.angleTextView setNeedsDisplay];
	self.radiusTextView.text = [NSString stringWithFormat:@"%.2f", self.rotatorView.radius];
	[self.radiusTextView setNeedsDisplay];
	self.xTextView.text = [NSString stringWithFormat:@"%.2f", self.rotatorView.cartesianPoint.x];
	[self.xTextView setNeedsDisplay];
	self.yTextView.text = [NSString stringWithFormat:@"%.2f", self.rotatorView.cartesianPoint.y];
	[self.yTextView setNeedsDisplay];
	self.valueTextView.text = [NSString stringWithFormat:@"%.2f", self.rotatorView.value];
	[self.valueTextView setNeedsDisplay];
	switch( self.rotatorView.style )
	{
	case NDRotatorStyleDisc:
		self.styleControl.selectedSegmentIndex = 0;
		break;
	case NDRotatorStyleRotate:
		self.styleControl.selectedSegmentIndex = 1;
		break;
	case NDRotatorStyleLinear:
		self.styleControl.selectedSegmentIndex = 2;
		break;
	}
	self.minimumDomainTextView.text = [NSString stringWithFormat:@"%.2f", self.rotatorView.minimumDomain/M_PI];
	[self.minimumDomainTextView setNeedsDisplay];
	self.maximumDomainTextView.text = [NSString stringWithFormat:@"%.2f", self.rotatorView.maximumDomain/M_PI];
	[self.maximumDomainTextView setNeedsDisplay];
	self.minimumRangeTextView.text = [NSString stringWithFormat:@"%.2f", self.rotatorView.minimumValue];
	[self.minimumRangeTextView setNeedsDisplay];
	self.maximumRangeTextView.text = [NSString stringWithFormat:@"%.2f", self.rotatorView.maximumValue];
	[self.maximumRangeTextView setNeedsDisplay];

	self.wrapConstrainButton.selected = self.rotatorView.wrapAround;
	[self.wrapConstrainButton setNeedsDisplay];
	self.continuousButton.selected = self.rotatorView.isContinuous;
	[self.continuousButton setNeedsDisplay];
	self.nextThumbTintButton.titleLabel.text = kThumbTintStr[self.rotatorView.thumbTint];
	[self.nextThumbTintButton setNeedsDisplay];
}

@end
