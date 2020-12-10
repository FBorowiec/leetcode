# Leetcode challenges

These are my C++ solutions to Leetcode problems. All problems have the same number as the ones on the [https://leetcode.com/](https://leetcode.com/) website.

## How to run the code locally with *Bazel* already installed on host

### Bazel installation

[Install Bazel](https://docs.bazel.build/versions/master/install.html)

Once you have successfully installed *Bazel* you can run the code using:

```bash
bazel test //problems/test:unit_tests
```

## Run the code inside a container

You can use my following Docker image to instantiate a container locally with Ubuntu and Bazel already installed:

```bash
docker run -it --rm framaxwlad/ubuntu_dev:latest
```

There you can simply clone the repository:

```bash
git clone https://github.com/FBorowiec/leetcode.git
cd leetcode/
```

And use the aforementioned commands to run the program:

```bash
bazel test //problems/test:unit_tests
```
