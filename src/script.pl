#!/usr/bin/perl

#script to populate register.img file with the values of the coefficients
#of the given polynomial(currently only second degree) and the interval for which to integrate it

#call of script should look like "script.pl input_file.txt > register.img"
#I've also attached a small example to give a feel for it

#Small caveat: if a coefficient is 1, explicitly write it (e.g. x^2+5x+6 ----> incorrect, 1x^2+5x+6 ----> correct)
#TODO(whoever chooses): Fix small caveat and generalise

use strict;
use warnings;

# Check if the input file is provided
if (@ARGV != 1) {
    die "Usage: $0 input_file.txt > register.img\n";
}

# Open the input file
open my $input_fh, '<', $ARGV[0] or die "Unable to open input file: $!\n";

# Read the polynomial and numbers from input file
my $polynomial = <$input_fh>;
chomp $polynomial;
my $numbers_line = <$input_fh>;
close $input_fh;

# Extract coefficients from the polynomial
my ($a, $b, $c) = extract_coefficients($polynomial);

# Write coefficients in hex format to the output file
printf "0x%08X\n", $a;
printf "0x%08X\n", $b;
printf "0x%08X\n", $c;

# Write the numbers from the second line of input_file.txt to the output file
my ($num1, $num2) = split /\s+/, $numbers_line;
printf "0x%08X\n", $num1;
printf "0x%08X\n", $num2;

# Write "0x00000000" 27 times to the output file
for (1..27) {
    printf "0x00000000\n";
}

sub extract_coefficients {
    my ($polynomial) = @_;

    # Extract coefficients from the polynomial
    my ($a, $b, $c) = $polynomial =~ /(\d*)x\^2\s*([\+\-]?\d*)x\s*([\+\-]?\d*)/;
    $a ||= 0;
    $b ||= 0;
    $c ||= 0;

    return ($a, $b, $c);
}
