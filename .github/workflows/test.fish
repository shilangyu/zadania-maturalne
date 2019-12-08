set lang $argv[1]

switch $lang
case python
	set ext py
case c++
	set ext cpp
case '*'
	echo "Unrecognized language: $lang"
	exit 1
end

function redecho
	echo -e '\033[0;31m'(string join ' ' $argv)'\033[0m'
end

function greenecho
	echo -e '\033[0;32m'(string join ' ' $argv)'\033[0m'
end

function test_dir
	set was_error 0
	cd $argv[1]

	for d in 20??/$lang
		if not test -e $d/main.$ext
			set was_error 1
			redecho $argv[1]/$d missing a main.$ext file. 
			continue
		end
		
		cd $d

		switch $lang
		case python
			set out (python main.py)
		case c++
			g++ main.cpp -o abc
			set out (./abc)
		end

		if not test -e wyniki.txt
			set was_error 1
			redecho $argv[1]/$d: main.$ext did not produce a wyniki.txt file. 
			cd ../..
			continue
		end

		set wyniki (cat wyniki.txt)
		if not test "$out" = "$wyniki"
			set was_error 1
			redecho $argv[1]/$d: main.$ext output does not match wyniki.txt. 
			cd ../..
			continue
		end

		greenecho $argv[1]/$d ✓
		cd ../..
	end

	cd ..
	return $was_error
end

test_dir nowa
set final_status $status
test_dir stara
set final_status (math $status + $final_status)

exit (test $final_status -eq 0)
