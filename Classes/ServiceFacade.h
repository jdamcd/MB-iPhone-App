//
//  ServiceFacade.h
//  Musicbrainz
//
//  Created by Jens Lukas on 6/4/10.
//  Copyright 2010 Jens Lukas <contact@jenslukas.com>
//
//  This program is made available under the terms of the MIT License.
//
//	Abstract: Facade for all service request, responsible for delgating retrieval and parsing of the data

#import <Foundation/Foundation.h>
#import "WebService.h"
#import "AbstractXMLParser.h"
#import "Search.h"
#import "Release.h"
#import "Artist.h"

@protocol DataCompleteDelegate
-(void) finishedRequest:(id) results;
@end

@interface ServiceFacade : NSObject <RequestCompleteDelegate, ParsingFinishedDelegate> {
	WebService *service;
	AbstractXMLParser *xmlParser;
	NSArray *results;
	id <DataCompleteDelegate> delegate;
	Search *searchInfo;
}

@property (nonatomic, retain) NSArray *results;
@property (nonatomic, retain) id <DataCompleteDelegate> delegate;
@property (nonatomic, retain) Search *searchInfo;

-(void) search:(Search *)search;
-(void) getRelease:(Release *)release;
-(void) getArtist:(Artist *)artist;
@end