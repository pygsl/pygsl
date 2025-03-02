import pygsl
import pygsl.init


def test_init_set_debug_level():
    pygsl.init.set_debug_level(1)
    pygsl.init.set_debug_level(0)


def test_set_debug_level():
    pygsl.set_debug_level(1)
    pygsl.set_debug_level(0)


if __name__ == "__main__":
    test_init_set_debug_level()
    test_set_debug_level()
