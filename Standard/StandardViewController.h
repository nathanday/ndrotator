//
//  StandardViewController.h
//  RotatingControllerView
//
//  Created by Nathan Day on 7/07/11.
//  Copyright 2011 Nathan Day. All rights reserved.
//

#import <UIKit/UIKit.h>
#include "NDRotator.h"

@interface StandardViewController : UIViewController <UITextFieldDelegate>
{
@private
	UITextField		* minimumDomainTextView;
	UITextField		* maximumDomainTextView;
	UITextField		* minimumRangeTextView;
	UITextField		* maximumRangeTextView;
	UISegmentedControl	* styleControl;
	UIButton		* wrapConstrainButton;
	UIButton		* continuousButton;
	UIButton *nextThumbTintButton;
	
	NDRotator		* rotatorView;

	UITextField		* angleTextView;
	UITextField		* radiusTextView;
	UITextField		* xTextView;
	UITextField		* yTextView;
	UITextField		* valueTextView;
}

@property(nonatomic, retain) IBOutlet UITextField		* minimumDomainTextView;
@property(nonatomic, retain) IBOutlet UITextField		* maximumDomainTextView;
@property(nonatomic, retain) IBOutlet UITextField		* minimumRangeTextView;
@property(nonatomic, retain) IBOutlet UITextField		* maximumRangeTextView;
@property (nonatomic, retain) IBOutlet UISegmentedControl	* styleControl;
@property (nonatomic, retain) IBOutlet UIButton			* wrapConstrainButton;
@property (nonatomic, retain) IBOutlet UIButton			* continuousButton;
@property (nonatomic, retain) IBOutlet UIButton			* nextThumbTintButton;

@property(nonatomic, retain) IBOutlet NDRotator			* rotatorView;

@property(nonatomic, retain) IBOutlet UITextField		* angleTextView;
@property(nonatomic, retain) IBOutlet UITextField		* radiusTextView;
@property(nonatomic, retain) IBOutlet UITextField		* xTextView;
@property(nonatomic, retain) IBOutlet UITextField		* yTextView;
@property(nonatomic, retain) IBOutlet UITextField		* valueTextView;

- (IBAction)changeMinimunDomainAction:(UITextField *)sender;
- (IBAction)changeMaximumDomainAction:(UITextField *)sender;
- (IBAction)changeMinimunRangeAction:(UITextField *)sender;
- (IBAction)changeMaximumRangeAction:(UITextField *)sender;

- (IBAction)changeStyleAction:(UISegmentedControl *)sender;
- (IBAction)changeSizeAction:(UISlider *)sender;
- (IBAction)changeWrapConstrainAction:(id)sender;
- (IBAction)changeContinuousAction:(id)sender;
- (IBAction)nextThumbTintAction:(id)sender;

- (IBAction)changeRotatorAction:(NDRotator *)sender;

@end
