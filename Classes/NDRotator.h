/*
	NDRotator.h
	RotatingControllerView

	Created by Nathan Day on 7/07/11.
	Copyright 2011 Nathan Day. All rights reserved.
 */

#import <UIKit/UIKit.h>

enum NDRotatorStyle
{
	NDRotatorStyleDisc,
	NDRotatorStyleRotate,
	NDRotatorStyleLinear
};

enum NDThumbTint
{
	NDThumbTintGrey,
	NDThumbTintRed,
	NDThumbTintGreen,
	NDThumbTintBlue,
	NDThumbTintYellow,
	NDThumbTintMagenta,
	NDThumbTintTeal,
	NDThumbTintOrange,
	NDThumbTintPink,
	NDThumbTintLime,
	NDThumbTintSpringGreen,
	NDThumbTintPurple,
	NDThumbTintAqua,
	NDThumbTintBlack
};

@interface NDRotator : UIControl

@property(assign)	CGFloat						value,
												minimumValue,
												maximumValue,
												minimumDomain,
												maximumDomain,
												linearSensitivity;
@property(assign,nonatomic)	CGFloat				angle;
@property(assign,nonatomic)	CGFloat				radius;
@property(assign)	CGPoint						cartesianPoint;
@property(readonly)	CGPoint						constrainedCartesianPoint;
@property			enum NDRotatorStyle			style;
@property			BOOL						wrapAround;
@property(nonatomic, getter=isContinuous) BOOL	continuous;
@property(nonatomic)		enum NDThumbTint	thumbTint;

/*!
	@methodgroup methods and properties to override to change look
 */

@property(readonly) CGRect		controlRect,
								thumbRect;

- (BOOL)drawDiscInRect:(CGRect)rect hilighted:(BOOL)hilighted;
- (BOOL)drawThumbInRect:(CGRect)rect hilighted:(BOOL)hilighted;

@end
