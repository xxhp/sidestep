//
//  SidestepAppDelegate.h
//  Sidestep
//
//  Created by Chetan Surpur on 11/18/10.
//  Copyright 2010 Chetan Surpur. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Sparkle/SUUpdater.h>
#import "SSHConnector.h"
#import "DefaultsController.h"
#import "LoginItemController.h"
#import "NetworkNotifier.h"
#import "ProxySetter.h"
#import "PasswordController.h"
#import "AppUtilities.h"
#import "GrowlMessage.h"
//#import <Growl/Growl.h>

@interface AppController : NSObject <GrowlApplicationBridgeDelegate> { //<NSApplicationDelegate> {
    NSWindow *window;
	
	IBOutlet NSMenu *statusMenu;
    NSStatusItem *statusItem;
	
	NSImage *statusImageDirectInsecure;
	NSImage *statusImageDirectSecure;
	NSImage *statusImageReroutedSecure;
	
	IBOutlet NSWindow *preferencesWindow;
	IBOutlet NSWindow *welcomeWindow;
	
	IBOutlet NSTabView *welcomeTabs;
	
	IBOutlet NSMenuItem *proxyServerStatus;
	IBOutlet NSMenuItem *connectionStatus;
	
	IBOutlet NSMenuItem *rerouteOrRestoreConnectionButton;
	
	SSHConnector *SSHconnector;
	DefaultsController *defaultsController;
	NetworkNotifier *networkNotifier;
	ProxySetter *proxySetter;
	
	GrowlMessage *growl;
	
	Boolean initiatedDelayedConnectionAttempt;
	int currentDelay;
	int retryCounter;
	
	Boolean testingConnection;
	IBOutlet NSTextField *testConnectionStatusField;
	
	IBOutlet NSTextField *testConnectionStatusFieldInPreferences;
	IBOutlet NSTextField *testConnectionStatusFieldInWelcome;
	
	NSTask *SSHConnection;
	Boolean SSHConnecting;
	Boolean SSHConnected;
	
	NSString *currentNetworkSecurityType;
}

- (void)openSSHConnectionAfterDelay :(int)delay;
- (void)testSSHConnection;
- (void)closeSSHConnection;
- (void)setRunOnLogin :(BOOL)value;

- (void)showRestartSidestepDialog;

- (void)preferencesClicked :(id)sender;
- (void)aboutClicked :(id)sender;

- (void)rerouteOrRestoreConnectionClicked :(id)sender;

- (void)testSSHConnectionClickedFromPreferences :(id)sender;
- (void)testSSHConnectionClickedFromWelcome :(id)sender;

- (void)helpWithProxyClicked :(id)sender;

- (void)nextClickedInWelcome :(id)sender;
- (void)finishClickedInWelcome :(id)sender;

- (void)toggleRunOnLoginClicked :(id)sender;

- (NSDictionary *) registrationDictionaryForGrowl;

@end
