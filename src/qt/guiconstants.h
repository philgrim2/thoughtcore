// Copyright (c) 2011-2015 The Bitcoin Core developers
// Copyright (c) 2014-2020 The Dash Core developers
// Copyright (c) 2018-2022 Thought Network Ltd
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef THOUGHT_QT_GUICONSTANTS_H
#define THOUGHT_QT_GUICONSTANTS_H

/* Milliseconds between model updates */
static const int MODEL_UPDATE_DELAY = 250;

/* AskPassphraseDialog -- Maximum passphrase length */
static const int MAX_PASSPHRASE_SIZE = 1024;

/* DashGUI -- Size of icons in status bar */
static const int STATUSBAR_ICONSIZE = 18;

/* DashGUI -- Size of button icons e.g. in SendCoinEntry or SignVerifyMessageDialog */
static const int BUTTON_ICONSIZE = 23;

static const bool DEFAULT_SPLASHSCREEN = true;

/** Defines the half in RGB space, basically a grey in the middle between black and white */
#define RGB_HALF 0x7f7f7f
/** Path to the icon ressource folder */
#define ICONS_PATH ":icons/"
/** Path to the movies ressource folder */
#define MOVIES_PATH ":movies/"

/* Tooltips longer than this (in characters) are converted into rich text,
   so that they can be word-wrapped.
 */
static const int TOOLTIP_WRAP_THRESHOLD = 80;

/* Maximum allowed URI length */
static const int MAX_URI_LENGTH = 255;

/* QRCodeDialog -- size of exported QR Code image */
#define QR_IMAGE_SIZE 300

/* Number of frames in spinner animation */
#define SPINNER_FRAMES 90

#define QAPP_ORG_NAME "Thought"
#define QAPP_ORG_DOMAIN "thought.live"
#define QAPP_APP_NAME_DEFAULT "Thought-Qt"
#define QAPP_APP_NAME_TESTNET "Thought-Qt-testnet"
#define QAPP_APP_NAME_DEVNET "Thought-Qt-%s"
#define QAPP_APP_NAME_REGTEST "Thought-Qt-regtest"

#endif // THOUGHT_QT_GUICONSTANTS_H
