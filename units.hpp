/**
 * Units
 * Created by Martin Steil on 2017.02.13.
 *
 * If not further specified the values for the fundamental constants were taken from [1].
 *
 * [1]  P. J. Mohr et. al., CODATA Recommended Values of the Fundamental Physical Constants: 2014
 *      http://arxiv.org/abs/1507.07956v1 - 16.05.09 22:50
 * [2]  U.S. Nautical Almanac Office et. al., The Astronomical Almanac - Selected Astronomical Constants 2016
 *      http://asa.usno.navy.mil/static/files/2016/Astronomical_Constants_2016.txt  - 16.05.09 23:50
 * [3]  Langage Objet pour la RElativité NumériquE (LORENE) - Lorene/C++/Include/unites.h
 *      http://www.lorene.obspm.fr/ - 16.10.04 14:27
 *
 */

#ifndef UNITS_HPP
#define UNITS_HPP

#include <cmath>

namespace units {
    //region Natural constants
    static constexpr double c0         = 299792458;    // Speed of light in vacuum [ms-1]
    static constexpr double G          = 6.67408e-11;  // Newtonian constant of gravitation [m3kg-1s-2]
    static constexpr double mu0over4pi = 1e-7;         // Magnetic vacuum permeability [mkgs-2A-2]
    static constexpr double kB         = 1.38064852e-23;   // Boltzmann constant [m2kgs-2K-1]
    static constexpr double hbar       = 1.054571800e-34;  // Planck constant over 2 pi [m2kgs-1]

    // Directly related values
    static constexpr double c0_2 = c0*c0;   // Speed of light in vacuum to the power of 2 [m2s-2]
    static constexpr double c0_3 = c0_2*c0; // Speed of light in vacuum to the power of 3 [m3s-3]
    static constexpr double c0_4 = c0_3*c0; // Speed of light in vacuum to the power of 4 [m4s-4]

    static constexpr double c0c0_cgs = c0_2 * 1e4; // Speed of light in vacuum squared in [cm2s-2] = 8.98755e+20
    //endregion

    //region Reference values
    static constexpr double qe = 1.6021766208e-19;  // Elementary charge [C]

    static constexpr double mn = 939.5654133;  // Neutron mass [MeV]
    static constexpr double mp = 938.2720813;  // Proton mass [MeV]
    static constexpr double me = 0.5109989461; // Electron mass [MeV]

    static constexpr double MSkg = 1.9884e+30;        // Solar mass from [2] [kg]
    static constexpr double MSkm = MSkg*G/c0_2*1e-3;  // Solar mass from [2] [km/MS] = 1.47657

    static constexpr double MEkg = 5.9722e+24;         // Earth mass from [2] [kg]
    static constexpr double MEkm = MEkg*G/c0_2*1e-3;   // Earth mass from [2] [km] = 4.4349e-06
    //endregion

    //region Gravitational units with G = c = mu0/(4 Pi) = 1
    // Nuclear units
    static constexpr double cfm3km3    = 1e54;             // Conversion factor [km-3/(fm-3)] = 1e+54
    static constexpr double cMeVkm     = G*qe/c0_4*1e3;    // Conversion factor [km/MeV] = 1.32379e-60
    static constexpr double cMeVfm3km2 = cMeVkm*cfm3km3;   // Conversion factor [km-2/(MeVfm-3)] = 1.32379e-06

    // CGS Units
    static constexpr double cdyncm2km2 = G/c0_4*1e5;   // Conversion factor [km-2/dyncm-2)] = 8.26245e-40
    static constexpr double cgcm3km2   = G/c0_2*1e9;   // Conversion factor [km-2/gcm-3)] = 7.42592e-19

    // SI Units
    static constexpr double cHzkm      = 1/c0*1e3;     // Conversion factor [km-1/Hz] = 3.33564e-6
    static constexpr double ckgm2s1km2 = G/c0_3*1e-6;  // Conversion factor [km2/kgm2s-1] = 2.47702e-30
    static constexpr double ckgm2km3   = G/c0_2*1e-9;  // Conversion factor [km3/kgm2] = 7.42592e-37
    static constexpr double ckgm3km2   = G/c0_2*1e6;   // Conversion factor [km-2/(kgm-3)] = 7.42592e-22
    //endregion

    //region Electro-magnetic GSU units
    static constexpr double cTkm       = 1.0/c0_2*0.02583424084427487*1e3;   // Conversion factor [km-1/T] = 2.87445e-16
    static constexpr double cA         = 1.0/c0_2*2.583424084427487e-9;       // Conversion factor [1/A] = 2.87445e-26
    static constexpr double cCkm       = 2.583424084427487e-9/c0*1e-3;      // Conversion factor [km/C] = 8.61738e-21
    static constexpr double cV         = 0.02583424084427487/c0_3;         // Conversion factor [1/V] = 9.58812e-28

    static constexpr double cAm2km2    = cA*1e-6;       // Conversion factor [km2/Am2] = 2.87445e-32
    static constexpr double cGskm      = cTkm*1e-4;     // Conversion factor [km-1/Gs] = 2.87445E-20
    static constexpr double cGTkm      = cTkm*1e+9;     // Conversion factor [km-1/GT] = 2.87445e-7
    //endregion

    //region Lorene Units
    static constexpr double LrhoNuc_si = 1.66e+17;                     // LORENE´s 'arbitrary' nuclear density [3] [kgm-3]
    static constexpr double LrhoNuc_cgs = LrhoNuc_si * 1e-3;           // LORENE´s 'arbitrary' nuclear density [3] [gcm-3] = 1.66e+14
    static constexpr double LrhoNuc_MeV = LrhoNuc_si*c0_2/qe*1e-51;    // LORENE´s 'arbitrary' nuclear density [3] [MeVfm-3] = 93.11917937
    static constexpr double LrhoNuc_km = LrhoNuc_si*ckgm3km2;          // LORENE´s 'arbitrary' nuclear density [3] [km-2] = 1.232702e-4

    static constexpr double LmB_MeV = 10*LrhoNuc_MeV;                  // LORENE´s baryon mass [3] [MeV] = 931.1917937
    static constexpr double LmB_km  = LmB_MeV*cMeVkm;                  // LORENE´s baryon mass [3] [km]  = 1.2327021e-57

    static constexpr double LnNuc_fm = 0.1;                            // LORENE´s 'arbitrary' nuclear baryon number density [3] [fm-3]
    static constexpr double LnNuc_km = LnNuc_fm*cfm3km3;               // LORENE´s 'arbitrary' nuclear baryon number density [3] [km-3] =  1e53
    //endregion

    //region Mathematical Constants
    static constexpr double M_2PI      = 6.28318530717958647692528676656; // 2 times Pi
    static constexpr double M_4PI      = 12.5663706143591729538505735331; // 4 times Pi
    static constexpr double M_PI_SQARE = 9.86960440108935861883449099988; // Pi**2
    static constexpr double M_PHI      = 1.61803398874989484820458683437; // Golden Ratio: (sqrt(5)+1)/2
    //endregion
}
#endif //UNITS_HPP
