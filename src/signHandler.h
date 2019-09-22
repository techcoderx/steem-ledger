/*******************************************************************************
*
*  (c) 2016 Ledger
*  (c) 2019 TechCoderX
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

void handleSign(uint8_t p1, uint8_t p2, uint8_t *dataBuffer, uint16_t dataLength, volatile unsigned int *flags, volatile unsigned int *tx);

/*
// Full list of Steem blockchain operations to be parsed
// To save space on the Nano S (which has very limited storage space), some transaction types which are very unlikely being made will not be supported (e.g. declining voting rights).
// Escrow transfer will not be supported in the first release but likely to be added in future wallet updates.
// 30 types of transactions are currently supported.
// DO NOT CHANGE THE ORDER AS DEFINED IN https://github.com/steemit/steem/blob/master/libraries/protocol/include/steem/protocol/operations.hpp
*/
static const char SteemOperations[47][29] = {
    "Vote",
    "Comment",
    "Trasfer",
    "Power Up",
    "Power Down",
    "Create Limit Order",
    "Cancel Limit Order",
    "Feed Price", // Not supported on wallet
    "Feed Publish",
    "Convert",
    "Create Account",
    "Update Acc", // Pre HF21, owner and active key only. Not supported on wallet
    "Update Witness", // Pre HF20, Not supported on wallet
    "Witness Vote",
    "Witness Proxy",
    "Pow", // Depreciated
    "Custom", // Not supported on wallet
    "Delete Comment",
    "Custom JSON",
    "Comment Options",
    "Power Down Route", // Not supported on wallet
    "Create Limit Order", // limit_order_create2
    "Claim Account",
    "Create Claimed Account",
    "Request Account Recovery",
    "Recover Account",
    "Change Recovery Account",
    "Escrow Transfer", // Future wallet update
    "Escrow Dispute", // Future wallet update
    "Escrow Release", // Future wallet update
    "Pow2", // Depreciated
    "Escrow Approve", // Future wallet update
    "Transfer To Savings",
    "Transfer From Savings",
    "Cancel Transfer From Savings",
    "Custom Binary", // Not supported on wallet
    "Decline Voting Rights", // Not supported on wallet
    "Reset Acc", // Depreciated
    "Set Reset Acc", // Depreciated
    "Claim Rewards",
    "Delegate Steem Power",
    "Create Acc With Delegation", // Depreciated
    "Update Witness",
    "Update Profile", // Posting key enabled of Account Update
    "Create Proposal",
    "Vote Proposal",
    "Remove Proposal"
};

// Transaction parameters

typedef struct vote_t {
    char voter[17];
    char author[17];
    char permlink[257];
    char weight[7];
} vote_t;