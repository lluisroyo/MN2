set terminal pngcairo
set output "errors.png"

set xrange[0:2]
set yrange[-1:1]

plot "err_exp.dat" title "Mètode Euler Explícit" lt 8 w lp, "err_imp.dat" title "Mètode Euler Implícit" lt 9 w lp, "err_crank.dat" title "Mètode Implícit (Crank-Nicholson)" lt 10 w lp
