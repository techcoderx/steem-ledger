/*******************************************************************************
*   (c) 2016 Ledger
*   (c) 2018 Taras Shchybovyk
*	(c) 2019 TechCoderX
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

#include <stdbool.h>
#include <stdint.h>

#define STEEM_PUB_KEY_LENGTH 53
#define STEEM_MEMO_MAX_LENGTH 2047

// Base58 encoding
bool b58enc(uint8_t *data, uint32_t binsz, char *b58, uint32_t *b58sz);

// Concatenate strings with integers
void itoa(int n, char s[]);