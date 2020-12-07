for file in $(ls $1)
do 
	if [[ ($file != "CMakeLists.txt") && ($file != "cycle.sh")]]
	then
		path_to_file="$1/$file"

		first_line=$(head -1 $path_to_file)
		check_comment=$(echo $first_line | cut -d':' -f1 | cut -d'C' -f2)
		check_comment="C$check_comment"

		if [[($check_comment == "COMMENT")]]
		then
			awk 'NR>1' $path_to_file >$path_to_file"_tmp";mv $path_to_file"_tmp" $path_to_file			
		fi
		current_date=$(date +"%d-%m-%y %H:%M")
		info_to_add="1i/* COMMENT:: $2, $3, $current_date*/"

		sed -i "$info_to_add" $path_to_file
		
	fi
done
