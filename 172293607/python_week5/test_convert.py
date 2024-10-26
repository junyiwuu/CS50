import pytest
from convert import convert


def test_conversion():
    assert convert(1) == 149597870700

def test_error():
    with pytest.raises(TypeError):
        convert("1")

def test_float_conversion():
    assert convert(0.001) == pytest.approx(149597870.691, abs=0.1)  #but also need some toleranc
