//
//  MegoPickerViewController.h
//  MegoCoinDemo
//
//  Created by  David -iphone on 15/04/16.
//  Copyright © 2016 Migital. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ELCImagePickerHeader.h"


@protocol MegoImagepickerDelegation <NSObject>

-(void)selectedImages:(NSArray*)images;

@end

@interface MegoPickerViewController : UIViewController<ELCImagePickerControllerDelegate>

@property(strong)id <MegoImagepickerDelegation> MegoPickerDelegate;


@end
