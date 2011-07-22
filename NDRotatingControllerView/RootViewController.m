//
//  RootViewController.m
//  NDRotatingControllerView
//
//  Created by Nathan Day on 14/07/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "RootViewController.h"
#import "StandardViewController.h"

@implementation RootViewController


- (void)viewDidLoad
{
	[super viewDidLoad];
	self.title = @"Menu";
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
	[super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
	[super viewDidDisappear:animated];
}

// Customize the number of sections in the table view.
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
	return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
	return 2;
}

// Customize the appearance of table view cells.
- (UITableViewCell *)tableView:(UITableView *)aTableView cellForRowAtIndexPath:(NSIndexPath *)anIndexPath
{
	NSParameterAssert( anIndexPath.length > 1 );

	UITableViewCell		* theCell = nil;
	static NSString		* kCellIdentifier = @"Cell";
	NSUInteger			theRowIndex = [anIndexPath indexAtPosition:1];

	theCell = [aTableView dequeueReusableCellWithIdentifier:kCellIdentifier];

	if(theCell == nil )
		theCell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:kCellIdentifier] autorelease];

	switch( theRowIndex )
	{
	case 0:
		theCell.textLabel.text = @"Standard";
		break;
		
	case 1:
		theCell.textLabel.text = @"Customised Look";
		break;

	default:
		NSAssert(NO, @"Unexpected row: %d", theRowIndex );
		break;
	}
	
    return theCell;
}

- (void)tableView:(UITableView *)aTableView didSelectRowAtIndexPath:(NSIndexPath *)anIndexPath
{
	NSParameterAssert( anIndexPath.length > 1 );
	
	NSUInteger			theRowIndex = [anIndexPath indexAtPosition:1];
	UIViewController	* theController = nil;
	switch( theRowIndex )
	{
	case 0:
		theController = [[StandardViewController alloc] init];
		break;
		
	case 1:
		break;
		
	default:
		NSAssert(NO, @"Unexpected row: %d", theRowIndex );
		break;
	}
	[self.navigationController pushViewController:theController animated:YES];
	[theController release];
}

- (void)didReceiveMemoryWarning
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Relinquish ownership any cached data, images, etc that aren't in use.
}

- (void)viewDidUnload
{
    [super viewDidUnload];

    // Relinquish ownership of anything that can be recreated in viewDidLoad or on demand.
    // For example: self.myOutlet = nil;
}

- (void)dealloc
{
    [super dealloc];
}

@end
