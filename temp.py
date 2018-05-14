import matplotlib.pyplot as plt
import export_lattice as ex
import numpy as np
import pybinding as pb

energy_scale = 3.06
def graphene_initial(onsite=(0, 0)):
    theta = np.pi / 3
    a1 = np.array([1 + np.cos(theta), np.sin(theta)])
    a2 = np.array([0, 2 * np.sin(theta)])
    lat = pb.Lattice(
        a1=a1,
        a2=a2
    )
    lat.add_sublattices(
        # name, position, and onsite potential
        ('A', [0, 0], onsite[0]),
        ('B', [1, 0], onsite[1])
    )
    lat.add_hoppings(
        ([0, 0], 'A', 'B', - 1 / energy_scale),
        ([-1, 0], 'A', 'B', - 1 / energy_scale),
        ([-1, 1], 'A', 'B', - 1 / energy_scale)
    )

    disorder = ex.Disorder(lat)
    disorder.add_disorder('A', 'Deterministic', 0.0, 0)
    disorder.add_disorder('B', 'Deterministic', 0.0, 0)

    return lat, disorder, []


lattice, disorder, disorded_structural = graphene_initial()

nx = ny = 2
lx = 128
ly = 128

configuration = ex.Configuration(divisions=[nx, ny], length=[lx, ly], boundaries=[True, True],
                                 is_complex=False, precision=1, energy_scale=energy_scale)

calculation = ex.Calculation(fname=['CondXY'],
                             num_moments=[8], num_random=[1],
                             num_disorder=[1])

modification = ex.Modification(magnetic_field=False)
ex.export_lattice(lattice, configuration, calculation, modification, 'example2.h5',
                  disorder=disorder, disorded_structural=disorded_structural)