/*
 * Open Chinese Convert
 *
 * Copyright 2010-2013 BYVoid <byvoid@byvoid.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ConversionChain.hpp"

using namespace Opencc;

ConversionChain::ConversionChain() {
}

ConversionChain::~ConversionChain() {
}

void ConversionChain::AddConversion(ConversionPtr conversion) {
  conversions.push_back(conversion);
}

string ConversionChain::Convert(const string& textToConvert) {
  string text = textToConvert;
  for (auto conversion : conversions) {
    text = conversion->Convert(text);
  }
  return text;
}
