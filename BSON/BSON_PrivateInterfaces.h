//
//  BSON_PrivateInterfaces.h
//  ObjCMongoDB
//
//  Copyright 2013 Paul Melnikow and other contributors
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//


//
// This file is imported internally by classes in the framework to interact with each other. Don't use it in
// your application. Use the classes' public interfaces instead.
//

#import "bson.h"
#import "NSString+BSONAdditions.h"
#import "NSData+BSONAdditions.h"
#import "BSONDocument.h"
#import "BSONEncoder.h"
#import "BSONIterator.h"
#import "BSONTypes.h"

@interface BSONDocument (Project)
- (id) initWithNativeDocument:(const bson *) b destroyWhenDone:(BOOL) destroyWhenDone;
/**
 Initializes a BSON document as a sub-object for a given iterator, which retains
 the object owning its bson* until deallocation.
 
 Since only the root document may is responsible to call bson_destroy, instances created
 with this method will not call bson_destroy on deallocation.
 */
- (BSONDocument *) initForEmbeddedDocumentWithIterator:(BSONIterator *) iterator
                                           dependentOn:(id) dependentOn;
+ (BSONDocument *) documentWithNativeDocument:(const bson *) b destroyWhenDone:(BOOL) destroyWhenDone;
- (const bson *) bsonValue;
@end

@interface BSONEncoder (Project)
- (bson *) bsonValue;
@end

@interface BSONIterator (Project)
- (BSONIterator *) initWithDocument:(BSONDocument *)document
             keyPathComponentsOrNil:(NSArray *) keyPathComponents;
- (bson_iterator *) nativeIteratorValue;
@end

@interface BSONObjectID (Project)
+ (BSONObjectID *) objectIDWithNativeOID:(const bson_oid_t *) objectIDPointer;
- (bson_oid_t) oid;
- (const bson_oid_t *) objectIDPointer;
@end

@interface BSONTimestamp (Project)
+ (BSONTimestamp *) timestampWithNativeTimestamp:(bson_timestamp_t)timestamp;
- (bson_timestamp_t *) timestampPointer;
@end
