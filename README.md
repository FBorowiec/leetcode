# These are my solution to Leetcode problems

Requires Bazel

## Install gtest on Linux

<code>sudo apt-get install libgtest-dev cmake</code>

<code>cd /usr/src/googletest/googletest</code>

<code>sudo mkdir build</code>

<code>cd build</code>

<code>sudo cmake ..</code>

<code>sudo make</code>

<code>sudo cp libgtest* /usr/lib/</code>

<code>cd ..</code>

<code>sudo rm -rf build</code>

<code>sudo mkdir /usr/local/lib/googletest</code>

<code>sudo ln -s /usr/lib/libgtest.a /usr/local/lib/googletest/libgtest.a</code>

<code>sudo ln -s /usr/lib/libgtest_main.a /usr/local/lib/googletest/libgtest_main.a</code>
