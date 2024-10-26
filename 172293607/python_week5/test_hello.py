from hello import hello

def test_default():
    assert hello() == "hello, world"


def test_argument():
    assert hello("David") == "hello, David";



def test_loop():
    for name in ["herminoe", "harry", "ron"]:
        assert hello(name) == f"hello, {name}"


