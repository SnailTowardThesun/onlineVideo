/*
MIT License

Copyright (c) 2019 ME_Kun_Han

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef __MS_COMMON_HEADER__
#define __MS_COMMON_HEADER__

#include <sstream>

namespace ms_common {

    const int VERSION_MAJOR = 0;
    const int VERSION_MINOR = 0;
    const int VERSION_BUILD = 0;
    const int VERSION_REVISION = 1;

    std::string version() {
        std::stringstream ss;
        ss << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_BUILD << "."
           << VERSION_REVISION;
        return ss.str();
    }
} // namespace ms_common

#endif