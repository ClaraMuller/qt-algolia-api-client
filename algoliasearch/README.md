# Algolia Search API Client for Qt5

[Algolia Search](https://www.algolia.com) is a hosted search engine capable of
delivering realtime results from the first keystroke.

The **Algolia Search API Client for Qt5** lets you easily use the
[Algolia Search REST API](https://www.algolia.com/doc/rest-api/search) from your
C++ code.

## How to build the client API

You need a compiler with the support of C++14, git, cmake and of course Qt5.

### Download sources

```bash
git clone git@github.com:algolia/algoliasearch-client-qt5.git
```

### Create a build directory

```bash
cd algoliasearch-client-qt5
mkdir build
cd build
```

### Build sources

You need to set the cmake prefix path with the Qt5 path.

For example with clang as compiler and Qt5 in version 5.12.0

```bash
cmake -DCMAKE_PREFIX_PATH:PATH=/${HOME}/Qt/5.12.0/clang_64 ..
make -j
```

If you want to build shared library, you need to run cmake with correct options

```bash
cmake -DCMAKE_PREFIX_PATH:PATH=/${HOME}/Qt/5.12.0/clang_64 -DBUILD_SHARED_LIBS:BOOL=ON..
make -j
```


### Install the client library

```bash
make install
```

Now you can use the AlgoliaSearch client library.
