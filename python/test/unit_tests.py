import unittest


def run_tests() -> None:
    loader = unittest.TestLoader()
    tests = loader.discover("./python/test/", "*_test.py")

    runner = unittest.TextTestRunner()
    result = runner.run(tests)

    if result.failures:
        raise ValueError("Unit tests failed!")


if __name__ == "__main__":
    run_tests()
