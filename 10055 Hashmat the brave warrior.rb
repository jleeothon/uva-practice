begin
	while true
		a = gets.split
		a[0] = a[0].to_i
		a[1] = a[1].to_i
		puts ( (a[0] - a[1]).magnitude )
	end
rescue
end