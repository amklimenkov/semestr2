min_NMAX=100
max_NMAX=10000
step_NMAX=500

versions="1 2 3"
sizes=$(seq 0 $step_NMAX $max_NMAX)
sizes="$min_NMAX ${sizes:1}"

rm -f ./apps/*.exe || exit

if ! [ -d ./apps ]; then
    mkdir apps
fi

echo start compilation

for ver in $versions; do
    for size in $sizes; do
        if [ "$ver" == "2" ]; then
            gcc -std=gnu99 -Wall -Werror -Wpedantic -DNMAX="${size}"\
            -Wextra -Wfloat-conversion -Wfloat-equal -o0\
            -Wvla -o ./apps/app"${ver}"_"${size}"_fi.exe ./src/main"${ver}".c ./src/formal_index_sort.c

            gcc -std=gnu99 -Wall -Werror -Wpedantic -DNMAX="${size}"\
            -Wextra -Wfloat-conversion -Wfloat-equal -o0\
            -Wvla -o ./apps/app"${ver}"_"${size}"_ptr.exe ./src/main"${ver}".c ./src/pointer_sort.c

            gcc -std=gnu99 -Wall -Werror -Wpedantic -DNMAX="${size}"\
            -Wextra -Wfloat-conversion -Wfloat-equal -o0\
            -Wvla -o ./apps/app"${ver}"_"${size}"_idx.exe ./src/main"${ver}".c ./src/index_sort.c
            break
        fi
        gcc -std=gnu99 -Wall -Werror -Wpedantic -DNMAX="${size}"\
        -Wextra -Wfloat-conversion -Wfloat-equal -o0\
        -Wvla -o ./apps/app"${ver}"_"${size}"_fi.exe ./src/main"${ver}".c ./src/formal_index_sort.c ./src/statistic.c -lm

        gcc -std=gnu99 -Wall -Werror -Wpedantic -DNMAX="${size}"\
        -Wextra -Wfloat-conversion -Wfloat-equal -o0\
        -Wvla -o ./apps/app"${ver}"_"${size}"_ptr.exe ./src/main"${ver}".c ./src/pointer_sort.c ./src/statistic.c -lm

        gcc -std=gnu99 -Wall -Werror -Wpedantic -DNMAX="${size}"\
        -Wextra -Wfloat-conversion -Wfloat-equal -o0\
        -Wvla -o ./apps/app"${ver}"_"${size}"_idx.exe ./src/main"${ver}".c ./src/index_sort.c ./src/statistic.c -lm 

        
    done
done
echo succefully compilated
