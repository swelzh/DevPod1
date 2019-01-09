//
//  MXViewController.m
//  DevPod1
//
//  Created by swelzh on 01/07/2019.
//  Copyright (c) 2019 swelzh. All rights reserved.
//

#import "MXViewController.h"
#import "DevPod1.h"

@interface MXViewController ()

@end

@implementation MXViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    Car *car = [[Car alloc] init];
    NSLog(@"%@",car.description);
    
    Animals *animal = [[Animals alloc] init];
    [animal fly];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
