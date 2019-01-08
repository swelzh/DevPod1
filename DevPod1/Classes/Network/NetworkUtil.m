//
//  NetworkUtil.m
//  DevPod1
//
//  Created by swelzh on 2019/1/8.
//

#import "NetworkUtil.h"

@implementation NetworkUtil

+ (void)request{
    NSURLSessionConfiguration *configuration = [NSURLSessionConfiguration defaultSessionConfiguration];
    AFURLSessionManager *manager = [[AFURLSessionManager alloc] initWithSessionConfiguration:configuration];
    
    NSURL *URL = [NSURL URLWithString:@"https://images.zsxq.com/FtVJzyJ7sfuheOr9m37cnICoMGmw?imageMogr2/auto-orient/thumbnail/800x/format/jpg/blur/1x0/quality/75&e=1874736000&token=kIxbL07-8jAj8w1n4s9zv64FuZZNEATmlU_Vm6zD:6Ny0EsCqMQUd1Xy7m2tlvxm5kgo="];
    NSURLRequest *request = [NSURLRequest requestWithURL:URL];
    
    NSURLSessionDownloadTask *downloadTask = [manager downloadTaskWithRequest:request progress:nil destination:^NSURL *(NSURL *targetPath, NSURLResponse *response) {
        NSURL *documentsDirectoryURL = [[NSFileManager defaultManager] URLForDirectory:NSDocumentDirectory inDomain:NSUserDomainMask appropriateForURL:nil create:NO error:nil];
        return [documentsDirectoryURL URLByAppendingPathComponent:[response suggestedFilename]];
    } completionHandler:^(NSURLResponse *response, NSURL *filePath, NSError *error) {
        NSLog(@"File successfully downloaded to: %@", filePath);
    }];
    [downloadTask resume];
}

@end
