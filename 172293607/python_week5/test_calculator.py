import pytest
from calculator import square

def test_square():

    assert square(2) == 4
    assert square(3) == 9

def test_str():
    with pytest.raises(TypeError):
        square("cat")

if __name__ ==  "__main__":
    main()

