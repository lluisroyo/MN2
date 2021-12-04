set terminal pngcairo
set output "errors.png"

set key font "helvetica,10"

set xrange[0:2]
set yrange[0:0.75]
set xlabel "x [cm]"
set ylabel " Error absoluto [℃]"
plot "err_exp.dat" title "Método Euler Explícito" lt 8 w lp, "err_imp.dat" title "Método Euler Implícito" lt 9 w lp, "err_crank.dat" title "Método Implícito (Crank-Nicholson)" lt 10 w lp
