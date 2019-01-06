#!/usr/bin/perl

$problem = $ARGV[0];

$gccOutput = `gcc $problem.c -o $problem.o`;
print $gccOutput;
if ($gccOutput ne "") {
	exit;
} else {
	print "Compilation successful!\n"
}

`./$problem.o < $problem.in > $problem.log`;

print "===============\nActual results\n---------------\n";
print `cat $problem.log`;

print "===============\nExpected results\n---------------\n";
print `cat $problem.out`;

print "===============\nDifferences\n---------------\n";
$differences = `diff $problem.log $problem.out`;
if ($differences ne "") {
	print $differences;
} else {
	print "No differences!\n";
}
