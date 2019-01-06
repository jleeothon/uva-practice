

TEST_END = '@'
PROB_END = '#'

class Country
	attr_accessor name, g, s, b
	
	include Comparable
	
	def initialize name, g, s, b
		@name = name
		@g = g
		@s = s
		@b = b
	end

	def <=> other
		return other.g > @g ? 1 : -1 if @g != other.g
		return other.s > @s ? 1 : -1 if @s != other.s
		return other.b > @b ? 1 : -1 if @b != other.b
		return @name <=> other.name
	end
end

sorted_set = SortedSet.new

while true
	line = gets
	line = line.scan(/ /)
	if line == PROB_END or line == TEST_END then
		sorted_set.each do |country| puts(country.name)
		puts "@" if line == TEST_END
	end
	sorted_set << (Country.new line[0], line[1], line[2], line[3])
	break if line == PROB_END
end
