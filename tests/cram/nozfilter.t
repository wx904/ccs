Test to ensure the Z filtering can be disabled, the NaN parsing appears a bit finicky on some platforms

  $ $TESTDIR/../../bin/ccs --zmws=111715 --minZScore=NaN $TESTDIR/../data/tiny.bam nofilter.fq
  $ cat nofilter.fq
  @m150404_101626_42267_c100807920800000001823174110291514_s1_p0/111715/ccs np:i:24 rq:f:0.999988
  GCGTCGGATCGCCAACAACATGCCGGAACAGTACGACGAAAAGCCGCAGGTACAGCAGGTAGCGCAGATCATCAACGGTGTGTTCAGCCAGTTACTGGCAACTTTCCCGGCGAGCCTGGCTAACCGTGACCAGAACGAAGTGAACGAAATCCGTCGCCAGTGGGTTCTGGCTTTTCGGGAAAACGGGATCACCACGATGGAACAGGTTAACGCAGGAATGCGCGTAGCCCGTCGGCAGAATCGACCATTTCTGCCATCACCCGGGCAGTTTGTTGCATGGTGCCGGGAAGAAGCATCCGTTACCGCCGGACTGCCAAACGTCAGCGAGCTGGTTGATATGGTTTACGAGTATTGCCGGAAGCGAGGCCTGTATCCGGATGCGGAGTCTTATCCGTGGAAATCAAACGCGCACTACTGGCTGGTTACCAACCTGTATCAGAACATGCGGGCCAATGCGCTTACTGATGCGGAATTACGCCGTAAGGCCGCAGATGAGCTTGTCCATATGACTGCGAGAATTAACCGTGGTGAGGCGATCCCTGAACCAGTAAAACAACTTCCTGTCATGGGCGGTAGACCTCTAAATCGTGCACAGGCTCTGGCGAAGATCGCAGAAATCAAAGCTAAGTTCGGACTGAAAGGAGCAAGTGTATGACGGGCAAAGAGGCAATTATTCATTACCTGGGGACGCATAATAGCTTCTGTGCGCCGGACGTTGCCGCGCTAACAGGCGCAACAGTAACCAGCATAAATCAGGCCGCGGCTAAAATGGCACGGGCAGGTCTTCTGGTTATCGAAGGTAAGGTCTGGCGAA
  +
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~u~~~~~~~~~~~m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~i~~~~~~~~~}~~~~5~~g~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~T~~z~~~~~u~~~~~~~~~~~~~~~u~~~~~~~~~~~~~~~~~~~~m~s~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~~~~y~~~~~~~~~~~~~~~~~o~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~o~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~d~~~~s~~~~~~P~~~~~~~~~~~~~~~~~s~~~~~~~~~~~~~~t~~~~~~~~~~~~~~~~~~~~~b~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~d~~~~~~~~~~~~~~~~~~v~~~~~~~x~~~~~~~~~~~~~~~v~~p~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~}~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~g~~~~~~~w~~~~~~~u~~~~~~~~~p~~~~u~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
