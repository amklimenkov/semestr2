#!/bin/bash
find_project_directory() {
    if pwd | grep -q "func_tests/data";then
        project_directory=./../..
    elif pwd | grep -q "func_tests/scripts";then
        project_directory=./../..
    elif pwd | grep -q "func_tests";then
        project_directory=./..
    else
        project_directory=.
    fi
    echo "$project_directory"
}

failed_test_counter=0
project_directory=$(find_project_directory)
cd "$project_directory" || exit

# перебор позитивных тестов
pos_test_count=$(find ./func_tests/data/ -name "pos_*_in.txt" | wc -l)
failed_pos_counter=0
for (( i=1;i<=pos_test_count;i++ ))
do 
    if [[ $i -lt 10 ]];then
        if [[ "$1" == "-v" || "$1" == "--verbose" ]];then
            ./func_tests/scripts/pos_case.sh ./func_tests/data/pos_0"$i"_in.txt ./func_tests/data/pos_0"$i"_out.txt ./func_tests/data/pos_0"$i"_args.txt -v
        fi
        if ! ./func_tests/scripts/pos_case.sh ./func_tests/data/pos_0"$i"_in.txt ./func_tests/data/pos_0"$i"_out.txt ./func_tests/data/pos_0"$i"_args.txt;then
            failed_pos_counter=$((failed_pos_counter + 1))
        fi
    else
        if [[ "$1" == "-v" || "$1" == "--verbose" ]];then
            ./func_tests/scripts/pos_case.sh ./func_tests/data/pos_"$i"_in.txt ./func_tests/data/pos_"$i"_out.txt ./func_tests/data/pos_"$i"_args.txt -v
        fi
        if ! ./func_tests/scripts/pos_case.sh ./func_tests/data/pos_"$i"_in.txt ./func_tests/data/pos_"$i"_out.txt ./func_tests/data/pos_"$i"_args.txt;then
            failed_pos_counter=$((failed_pos_counter + 1))
        fi
    fi
    
done

echo POS PASSED: $((pos_test_count - failed_pos_counter))/"$pos_test_count"


#перебор негативных тестов
neg_test_count=$(find ./func_tests/data/ -name "neg_*_in.txt" | wc -l)
failed_neg_counter=0
for (( i=1;i<=neg_test_count;i++ ))
do 
    if [[ $i -lt 10 ]];then
        if [[ "$1" == "-v" || "$1" == "--verbose" ]];then
            ./func_tests/scripts/neg_case.sh ./func_tests/data/neg_0"$i"_in.txt ./func_tests/data/neg_0"$i"_args.txt -v
        fi
        if ! ./func_tests/scripts/neg_case.sh ./func_tests/data/neg_0"$i"_in.txt ./func_tests/data/neg_0"$i"_args.txt;then
            failed_neg_counter=$((failed_neg_counter + 1))
        fi
    else
        if [[ "$1" == "-v" || "$1" == "--verbose" ]];then
            ./func_tests/scripts/neg_case.sh ./func_tests/data/neg_"$i"_in.txt ./func_tests/data/neg_"$i"_args.txt -v
        fi
        if ! ./func_tests/scripts/neg_case.sh ./func_tests/data/neg_"$i"_in.txt ./func_tests/data/neg_"$i"_args.txt;then
            failed_neg_counter=$((failed_neg_counter + 1))
        fi
    fi
done


echo NEG PASSED: $((neg_test_count - failed_neg_counter))/"$neg_test_count"


failed_test_counter=$((failed_neg_counter + failed_pos_counter))

echo PASSED: $((neg_test_count + pos_test_count - failed_test_counter))/"$((pos_test_count + neg_test_count))"


exit $failed_test_counter
