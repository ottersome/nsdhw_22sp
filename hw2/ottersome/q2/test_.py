import vector as vec
import numpy as np

def func(x):
    return x + 1


def test_answer():
    err_diff = 0.01
    vec1 = vec.Vector(1,-2)
    print("Our vector1 is : {}".format(vec1))
    vec2 = vec.Vector(-2,1)
    angle1 = vec.get_angle_rad(vec1,vec2)
    print("Calculating the angle between vectors : {}".format(angle1))
    assert angle1 - np.arccos(-4/5) < err_diff


    vec1 = vec.Vector(np.cos(np.pi/2),np.cos(np.pi/2))
    vec2 = vec.Vector(1,0)
    angle2 = vec.get_angle_rad(vec1,vec2)
    assert angle2 - np.pi/4 < err_diff

    vec1 = vec.Vector(0,1)
    vec2 = vec.Vector(1,0)
    angle3 = vec.get_angle_rad(vec1,vec2)
    assert angle3 - np.pi/2 < err_diff

    vec1 = vec.Vector(-1,1)
    vec2 = vec.Vector(1,1)
    angle4 = vec.get_angle_rad(vec1,vec2)
    assert angle4 - np.pi < err_diff

    vec1 = vec.Vector(0,1)
    vec2 = vec.Vector(-1,0)
    angle5 = vec.get_angle_rad(vec1,vec2)
    assert angle5 - np.pi < err_diff
