<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:template match="/">

	<br></br>

	Total number of nodes in achtype_mapping old: 

	<xsl:value-of select="count(document('achtype_mapping_v1_orig.xml')/Lookup/Data/*)" />

		<br></br>

	Total number of nodes in achtype_mapping new: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/*)" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 1: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 1])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 2: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 2])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 3: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 3])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 4: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 4])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 5: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 5])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 6: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 6])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 7: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 7])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 8: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 8])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 9: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 9])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 10: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 10])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 11: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 11])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 12: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 12])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 13: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 13])" />

	<br></br>

		Total number of nodes in achtype_mapping for witdrawal: 

	<xsl:value-of select="count(document('withdrawal_transactions.xml')/Lookup/Data/*)" />

	<br></br>

<xsl:for-each select="document('bank_transaction_type_mapping_test.xml')/Lookup/Data/Entry" >

	<xsl:variable name="btm" select="."/>

	<xsl:for-each select="document('achtype_mapping_v1_orig.xml')/Lookup/Data/Entry[transaction_type = $btm/transaction_type and transaction_subtype = $btm/transaction_subtype and flags = $btm/flags and flags2 = $btm/flags2 and flags3 = $btm/flags3] " >

	<xsl:variable name="achtype" select="ach_type"/>

	<xsl:variable name="vndr_cd" select="document('achtype_mapping_trie.xml')/Lookup/Data/Entry[ach_type = $achtype]/vendor_code"/>

<!--xsl:choose>



<xsl:when test="transaction_type = '(AUDDIS)'  "-->

<!--xsl:when test="transaction_type = 'A'  and (not(flags = '%') or not(flags2 = '1') and not(flags3 = '%')) "-->

<!--xsl:when test="transaction_type = 'A'  and ( not(transaction_subtype = '%') or not(flags = '%') or not(flags2 = '%') or not(flags3 = '%')) "-->

	&lt;Entry&gt;<br></br>

			 &lt;transaction_type&gt;<xsl:value-of select="$btm/bank_transaction_type"/>&lt;/transaction_type&gt;<br></br>

			 <!--&lt;transaction_subtype&gt;<xsl:value-of select="transaction_subtype"/>&lt;/transaction_subtype&gt;<br></br>

			 &lt;flags&gt;<xsl:value-of select="flags"/>&lt;/flags&gt;<br></br>

			 &lt;flags2&gt;<xsl:value-of select="flags2"/>&lt;/flags2&gt;<br></br>

			 &lt;flags3&gt;<xsl:value-of select="flags3"/>&lt;/flags3&gt;<br></br>-->

			 &lt;transaction_country_code&gt;<xsl:value-of select="transaction_country_code"/>&lt;/transaction_country_code&gt;<br></br>

			 &lt;currency_code&gt;<xsl:value-of select="currency_code"/>&lt;/currency_code&gt;<br></br>

			 &lt;user_country_or_region&gt;<xsl:value-of select="user_country_or_region"/>&lt;/user_country_or_region&gt;<br></br>

			 &lt;seller_country&gt;<xsl:value-of select="seller_country"/>&lt;/seller_country&gt;<br></br>

			 &lt;ach_flags&gt;<xsl:value-of select="ach_flags"/>&lt;/ach_flags&gt;<br></br>

			 &lt;bank_name&gt;<xsl:value-of select="bank_name"/>&lt;/bank_name&gt;<br></br>

			 &lt;bank_capability&gt;<xsl:value-of select="bank_capability"/>&lt;/bank_capability&gt;<br></br>

			 &lt;transaction_attempt&gt;<xsl:value-of select="transaction_attempt"/>&lt;/transaction_attempt&gt;<br></br>

			 &lt;ach_type&gt;<xsl:value-of select="ach_type"/>&lt;/ach_type&gt;<br></br>

			 &lt;vendor_code&gt;<xsl:value-of select="$vndr_cd"/>&lt;/vendor_code&gt;<br></br>

			 &lt;ach_backup_type&gt;<xsl:value-of select="ach_backup_type"/>&lt;/ach_backup_type&gt;<br></br>

			 &lt;WOWOSwitch&gt;<xsl:value-of select="WOWOSwitch"/>&lt;/WOWOSwitch&gt;<br></br>

			 &lt;achtype_throttle_wowo&gt;<xsl:value-of select="achtype_throttle_wowo"/>&lt;/achtype_throttle_wowo&gt;<br></br>

			 &lt;ach_throttle_algorithm&gt;<xsl:value-of select="ach_throttle_algorithm"/>&lt;/ach_throttle_algorithm&gt;<br></br>

			 &lt;ach_throttle_backup_type&gt;<xsl:value-of select="ach_throttle_backup_type"/>&lt;/ach_throttle_backup_type&gt;<br></br>

&lt;/Entry&gt;

<br></br>

</xsl:for-each>

</xsl:for-each>

</xsl:template>

</xsl:stylesheet>

	<!--/xsl:when-->



<!--

<xsl:when test="transaction_type = 'A'  and ( not(transaction_subtype = '%') or not(flags = '%') or not(flags2 = '%') or not(flags3 = '%')) ">

	&lt;Entry&gt;<br></br>

			 &lt;transaction_type&gt;<xsl:value-of select="transaction_type"/>&lt;/transaction_type&gt;<br></br>

			 &lt;transaction_subtype&gt;<xsl:value-of select="transaction_subtype"/>&lt;/transaction_subtype&gt;<br></br>

			 &lt;flags&gt;<xsl:value-of select="flags"/>&lt;/flags&gt;<br></br>

			 &lt;flags2&gt;<xsl:value-of select="flags2"/>&lt;/flags2&gt;<br></br>

			 &lt;flags3&gt;<xsl:value-of select="flags3"/>&lt;/flags3&gt;<br></br>

			 &lt;transaction_country_code&gt;<xsl:value-of select="transaction_country_code"/>&lt;/transaction_country_code&gt;<br></br>

			 &lt;currency_code&gt;<xsl:value-of select="currency_code"/>&lt;/currency_code&gt;<br></br>

			 &lt;user_country_or_region&gt;<xsl:value-of select="user_country_or_region"/>&lt;/user_country_or_region&gt;<br></br>

			 &lt;seller_country&gt;<xsl:value-of select="seller_country"/>&lt;/seller_country&gt;<br></br>

			 &lt;ach_flags&gt;<xsl:value-of select="ach_flags"/>&lt;/ach_flags&gt;<br></br>

			 &lt;bank_name&gt;<xsl:value-of select="bank_name"/>&lt;/bank_name&gt;<br></br>

			 &lt;bank_capability&gt;<xsl:value-of select="bank_capability"/>&lt;/bank_capability&gt;<br></br>

			 &lt;transaction_attempt&gt;<xsl:value-of select="transaction_attempt"/>&lt;/transaction_attempt&gt;<br></br>

			 &lt;ach_type&gt;<xsl:value-of select="ach_type"/>&lt;/ach_type&gt;<br></br>

			 &lt;ach_backup_type&gt;<xsl:value-of select="ach_backup_type"/>&lt;/ach_backup_type&gt;<br></br>

			 &lt;WOWOSwitch&gt;<xsl:value-of select="WOWOSwitch"/>&lt;/WOWOSwitch&gt;<br></br>

			 &lt;achtype_throttle_wowo&gt;<xsl:value-of select="achtype_throttle_wowo"/>&lt;/achtype_throttle_wowo&gt;<br></br>

			 &lt;ach_throttle_algorithm&gt;<xsl:value-of select="ach_throttle_algorithm"/>&lt;/ach_throttle_algorithm&gt;<br></br>

			 &lt;ach_throttle_backup_type&gt;<xsl:value-of select="ach_throttle_backup_type"/>&lt;/ach_throttle_backup_type&gt;<br></br>

&lt;/Entry&gt;

<br></br>

	</xsl:when>



<xsl:when test="transaction_type = 'H' and transaction_subtype = 'L'">

	&lt;Entry&gt;<br></br>

			 &lt;transaction_type&gt;5&lt;/transaction_type&gt;<br></br>

			 &lt;transaction_country_code&gt;<xsl:value-of select="transaction_country_code"/>&lt;/transaction_country_code&gt;<br></br>

			 &lt;currency_code&gt;<xsl:value-of select="currency_code"/>&lt;/currency_code&gt;<br></br>

			 &lt;user_country_or_region&gt;<xsl:value-of select="user_country_or_region"/>&lt;/user_country_or_region&gt;<br></br>

			 &lt;seller_country&gt;<xsl:value-of select="seller_country"/>&lt;/seller_country&gt;<br></br>

			 &lt;ach_flags&gt;<xsl:value-of select="ach_flags"/>&lt;/ach_flags&gt;<br></br>

			 &lt;bank_name&gt;<xsl:value-of select="bank_name"/>&lt;/bank_name&gt;<br></br>

			 &lt;ach_type&gt;<xsl:value-of select="ach_type"/>&lt;/ach_type&gt;<br></br>

			 &lt;ach_backup_type&gt;<xsl:value-of select="ach_backup_type"/>&lt;/ach_backup_type&gt;<br></br>

			 &lt;WOWOSwitch&gt;<xsl:value-of select="WOWOSwitch"/>&lt;/WOWOSwitch&gt;<br></br>

			 &lt;achtype_throttle_wowo&gt;<xsl:value-of select="achtype_throttle_wowo"/>&lt;/achtype_throttle_wowo&gt;<br></br>

			 &lt;ach_throttle_algorithm&gt;<xsl:value-of select="ach_throttle_algorithm"/>&lt;/ach_throttle_algorithm&gt;<br></br>

			 &lt;ach_throttle_backup_type&gt;<xsl:value-of select="ach_throttle_backup_type"/>&lt;/ach_throttle_backup_type&gt;<br></br>

&lt;/Entry&gt;

<br></br>

	</xsl:when>





	<xsl:when test="transaction_type = 'H' and flags = 33554432 and flags3 = 32">

	&lt;Entry&gt;<br></br>

			 &lt;transaction_type&gt;1&lt;/transaction_type&gt;<br></br>

			 &lt;transaction_country_code&gt;<xsl:value-of select="transaction_country_code"/>&lt;/transaction_country_code&gt;<br></br>

			 &lt;currency_code&gt;<xsl:value-of select="currency_code"/>&lt;/currency_code&gt;<br></br>

			 &lt;user_country_or_region&gt;<xsl:value-of select="user_country_or_region"/>&lt;/user_country_or_region&gt;<br></br>

			 &lt;seller_country&gt;<xsl:value-of select="seller_country"/>&lt;/seller_country&gt;<br></br>

			 &lt;ach_flags&gt;<xsl:value-of select="ach_flags"/>&lt;/ach_flags&gt;<br></br>

			 &lt;bank_name&gt;<xsl:value-of select="bank_name"/>&lt;/bank_name&gt;<br></br>

			 &lt;ach_type&gt;<xsl:value-of select="ach_type"/>&lt;/ach_type&gt;<br></br>

			 &lt;ach_backup_type&gt;<xsl:value-of select="ach_backup_type"/>&lt;/ach_backup_type&gt;<br></br>

			 &lt;WOWOSwitch&gt;<xsl:value-of select="WOWOSwitch"/>&lt;/WOWOSwitch&gt;<br></br>

			 &lt;achtype_throttle_wowo&gt;<xsl:value-of select="achtype_throttle_wowo"/>&lt;/achtype_throttle_wowo&gt;<br></br>

			 &lt;ach_throttle_algorithm&gt;<xsl:value-of select="ach_throttle_algorithm"/>&lt;/ach_throttle_algorithm&gt;<br></br>

			 &lt;ach_throttle_backup_type&gt;<xsl:value-of select="ach_throttle_backup_type"/>&lt;/ach_throttle_backup_type&gt;<br></br>

&lt;/Entry&gt;

<br></br>

	</xsl:when>

<xsl:when test="transaction_type = 'H' and flags = 33554432 and flags2 = 2048">

	&lt;Entry&gt;<br></br>

			 &lt;transaction_type&gt;2&lt;/transaction_type&gt;<br></br>

			 &lt;transaction_country_code&gt;<xsl:value-of select="transaction_country_code"/>&lt;/transaction_country_code&gt;<br></br>

			 &lt;currency_code&gt;<xsl:value-of select="currency_code"/>&lt;/currency_code&gt;<br></br>

			 &lt;user_country_or_region&gt;<xsl:value-of select="user_country_or_region"/>&lt;/user_country_or_region&gt;<br></br>

			 &lt;seller_country&gt;<xsl:value-of select="seller_country"/>&lt;/seller_country&gt;<br></br>

			 &lt;ach_flags&gt;<xsl:value-of select="ach_flags"/>&lt;/ach_flags&gt;<br></br>

			 &lt;bank_name&gt;<xsl:value-of select="bank_name"/>&lt;/bank_name&gt;<br></br>

			 &lt;ach_type&gt;<xsl:value-of select="ach_type"/>&lt;/ach_type&gt;<br></br>

			 &lt;ach_backup_type&gt;<xsl:value-of select="ach_backup_type"/>&lt;/ach_backup_type&gt;<br></br>

			 &lt;WOWOSwitch&gt;<xsl:value-of select="WOWOSwitch"/>&lt;/WOWOSwitch&gt;<br></br>

			 &lt;achtype_throttle_wowo&gt;<xsl:value-of select="achtype_throttle_wowo"/>&lt;/achtype_throttle_wowo&gt;<br></br>

			 &lt;ach_throttle_algorithm&gt;<xsl:value-of select="ach_throttle_algorithm"/>&lt;/ach_throttle_algorithm&gt;<br></br>

			 &lt;ach_throttle_backup_type&gt;<xsl:value-of select="ach_throttle_backup_type"/>&lt;/ach_throttle_backup_type&gt;<br></br>

&lt;/Entry&gt;

<br></br>

	</xsl:when>

<xsl:when test="transaction_type = 'H' and flags = 67108864">

	&lt;Entry&gt;<br></br>

			 &lt;transaction_type&gt;3&lt;/transaction_type&gt;<br></br>

			 &lt;transaction_country_code&gt;<xsl:value-of select="transaction_country_code"/>&lt;/transaction_country_code&gt;<br></br>

			 &lt;currency_code&gt;<xsl:value-of select="currency_code"/>&lt;/currency_code&gt;<br></br>

			 &lt;user_country_or_region&gt;<xsl:value-of select="user_country_or_region"/>&lt;/user_country_or_region&gt;<br></br>

			 &lt;seller_country&gt;<xsl:value-of select="seller_country"/>&lt;/seller_country&gt;<br></br>

			 &lt;ach_flags&gt;<xsl:value-of select="ach_flags"/>&lt;/ach_flags&gt;<br></br>

			 &lt;bank_name&gt;<xsl:value-of select="bank_name"/>&lt;/bank_name&gt;<br></br>

			 &lt;ach_type&gt;<xsl:value-of select="ach_type"/>&lt;/ach_type&gt;<br></br>

			 &lt;ach_backup_type&gt;<xsl:value-of select="ach_backup_type"/>&lt;/ach_backup_type&gt;<br></br>

			 &lt;WOWOSwitch&gt;<xsl:value-of select="WOWOSwitch"/>&lt;/WOWOSwitch&gt;<br></br>

			 &lt;achtype_throttle_wowo&gt;<xsl:value-of select="achtype_throttle_wowo"/>&lt;/achtype_throttle_wowo&gt;<br></br>

			 &lt;ach_throttle_algorithm&gt;<xsl:value-of select="ach_throttle_algorithm"/>&lt;/ach_throttle_algorithm&gt;<br></br>

			 &lt;ach_throttle_backup_type&gt;<xsl:value-of select="ach_throttle_backup_type"/>&lt;/ach_throttle_backup_type&gt;<br></br>

&lt;/Entry&gt;

<br></br>

	</xsl:when>



<xsl:when test="transaction_type = 'H' and transaction_subtype = 'L'">

	&lt;Entry&gt;<br></br>

			 &lt;transaction_type&gt;5&lt;/transaction_type&gt;<br></br>

			 &lt;transaction_country_code&gt;<xsl:value-of select="transaction_country_code"/>&lt;/transaction_country_code&gt;<br></br>

			 &lt;currency_code&gt;<xsl:value-of select="currency_code"/>&lt;/currency_code&gt;<br></br>

			 &lt;user_country_or_region&gt;<xsl:value-of select="user_country_or_region"/>&lt;/user_country_or_region&gt;<br></br>

			 &lt;seller_country&gt;<xsl:value-of select="seller_country"/>&lt;/seller_country&gt;<br></br>

			 &lt;ach_flags&gt;<xsl:value-of select="ach_flags"/>&lt;/ach_flags&gt;<br></br>

			 &lt;bank_name&gt;<xsl:value-of select="bank_name"/>&lt;/bank_name&gt;<br></br>

			 &lt;ach_type&gt;<xsl:value-of select="ach_type"/>&lt;/ach_type&gt;<br></br>

			 &lt;ach_backup_type&gt;<xsl:value-of select="ach_backup_type"/>&lt;/ach_backup_type&gt;<br></br>

			 &lt;WOWOSwitch&gt;<xsl:value-of select="WOWOSwitch"/>&lt;/WOWOSwitch&gt;<br></br>

			 &lt;achtype_throttle_wowo&gt;<xsl:value-of select="achtype_throttle_wowo"/>&lt;/achtype_throttle_wowo&gt;<br></br>

			 &lt;ach_throttle_algorithm&gt;<xsl:value-of select="ach_throttle_algorithm"/>&lt;/ach_throttle_algorithm&gt;<br></br>

			 &lt;ach_throttle_backup_type&gt;<xsl:value-of select="ach_throttle_backup_type"/>&lt;/ach_throttle_backup_type&gt;<br></br>

&lt;/Entry&gt;

<br></br>

	</xsl:when>



<xsl:when test="transaction_type = 'H'">

	&lt;Entry&gt;<br></br>

			 &lt;transaction_type&gt;4&lt;/transaction_type&gt;<br></br>

			 &lt;transaction_country_code&gt;<xsl:value-of select="transaction_country_code"/>&lt;/transaction_country_code&gt;<br></br>

			 &lt;currency_code&gt;<xsl:value-of select="currency_code"/>&lt;/currency_code&gt;<br></br>

			 &lt;user_country_or_region&gt;<xsl:value-of select="user_country_or_region"/>&lt;/user_country_or_region&gt;<br></br>

			 &lt;seller_country&gt;<xsl:value-of select="seller_country"/>&lt;/seller_country&gt;<br></br>

			 &lt;ach_flags&gt;<xsl:value-of select="ach_flags"/>&lt;/ach_flags&gt;<br></br>

			 &lt;bank_name&gt;<xsl:value-of select="bank_name"/>&lt;/bank_name&gt;<br></br>

			 &lt;ach_type&gt;<xsl:value-of select="ach_type"/>&lt;/ach_type&gt;<br></br>

			 &lt;ach_backup_type&gt;<xsl:value-of select="ach_backup_type"/>&lt;/ach_backup_type&gt;<br></br>

			 &lt;WOWOSwitch&gt;<xsl:value-of select="WOWOSwitch"/>&lt;/WOWOSwitch&gt;<br></br>

			 &lt;achtype_throttle_wowo&gt;<xsl:value-of select="achtype_throttle_wowo"/>&lt;/achtype_throttle_wowo&gt;<br></br>

			 &lt;ach_throttle_algorithm&gt;<xsl:value-of select="ach_throttle_algorithm"/>&lt;/ach_throttle_algorithm&gt;<br></br>

			 &lt;ach_throttle_backup_type&gt;<xsl:value-of select="ach_throttle_backup_type"/>&lt;/ach_throttle_backup_type&gt;<br></br>

&lt;/Entry&gt;

<br></br>

	</xsl:when> -->

<!--/xsl:choose-->

<!--/xsl:for-each-->

	<!--/xsl:template-->

<!--/xsl:stylesheet-->

<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:template match="/">

	<br></br>

	Total number of nodes in achtype_mapping old: 

	<xsl:value-of select="count(document('achtype_mapping_v1_orig.xml')/Lookup/Data/*)" />

		<br></br>

	Total number of nodes in achtype_mapping new: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/*)" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 1: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 1])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 2: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 2])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 3: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 3])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 4: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 4])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 5: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 5])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 6: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 6])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 7: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 7])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 8: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 8])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 9: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 9])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 10: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 10])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 11: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 11])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 12: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 12])" />

	<br></br>

	Total number of nodes in achtype_mapping v2 with transaction type 13: 

	<xsl:value-of select="count(document('achtype_mapping_v3.xml')/Lookup/Data/Entry[transaction_type = 13])" />

	<br></br>

		Total number of nodes in achtype_mapping for witdrawal: 

	<xsl:value-of select="count(document('withdrawal_transactions.xml')/Lookup/Data/*)" />

	<br></br>

<xsl:for-each select="document('bank_transaction_type_mapping_test.xml')/Lookup/Data/Entry" >

	<xsl:variable name="btm" select="."/>

	<xsl:for-each select="document('achtype_mapping_v1_orig.xml')/Lookup/Data/Entry[transaction_type = $btm/transaction_type and transaction_subtype = $btm/transaction_subtype and flags = $btm/flags and flags2 = $btm/flags2 and flags3 = $btm/flags3] " >

	<xsl:variable name="achtype" select="ach_type"/>

	<xsl:variable name="vndr_cd" select="document('achtype_mapping_trie.xml')/Lookup/Data/Entry[ach_type = $achtype]/vendor_code"/>

<!--xsl:choose>



<xsl:when test="transaction_type = '(AUDDIS)'  "-->

<!--xsl:when test="transaction_type = 'A'  and (not(flags = '%') or not(flags2 = '1') and not(flags3 = '%')) "-->

<!--xsl:when test="transaction_type = 'A'  and ( not(transaction_subtype = '%') or not(flags = '%') or not(flags2 = '%') or not(flags3 = '%')) "-->

	&lt;Entry&gt;<br></br>

			 &lt;transaction_type&gt;<xsl:value-of select="$btm/bank_transaction_type"/>&lt;/transaction_type&gt;<br></br>

			 <!--&lt;transaction_subtype&gt;<xsl:value-of select="transaction_subtype"/>&lt;/transaction_subtype&gt;<br></br>

			 &lt;flags&gt;<xsl:value-of select="flags"/>&lt;/flags&gt;<br></br>

			 &lt;flags2&gt;<xsl:value-of select="flags2"/>&lt;/flags2&gt;<br></br>

			 &lt;flags3&gt;<xsl:value-of select="flags3"/>&lt;/flags3&gt;<br></br>-->

			 &lt;transaction_country_code&gt;<xsl:value-of select="transaction_country_code"/>&lt;/transaction_country_code&gt;<br></br>

			 &lt;currency_code&gt;<xsl:value-of select="currency_code"/>&lt;/currency_code&gt;<br></br>

			 &lt;user_country_or_region&gt;<xsl:value-of select="user_country_or_region"/>&lt;/user_country_or_region&gt;<br></br>

			 &lt;seller_country&gt;<xsl:value-of select="seller_country"/>&lt;/seller_country&gt;<br></br>

			 &lt;ach_flags&gt;<xsl:value-of select="ach_flags"/>&lt;/ach_flags&gt;<br></br>

			 &lt;bank_name&gt;<xsl:value-of select="bank_name"/>&lt;/bank_name&gt;<br></br>

			 &lt;bank_capability&gt;<xsl:value-of select="bank_capability"/>&lt;/bank_capability&gt;<br></br>

			 &lt;transaction_attempt&gt;<xsl:value-of select="transaction_attempt"/>&lt;/transaction_attempt&gt;<br></br>

			 &lt;ach_type&gt;<xsl:value-of select="ach_type"/>&lt;/ach_type&gt;<br></br>

			 &lt;vendor_code&gt;<xsl:value-of select="$vndr_cd"/>&lt;/vendor_code&gt;<br></br>

			 &lt;ach_backup_type&gt;<xsl:value-of select="ach_backup_type"/>&lt;/ach_backup_type&gt;<br></br>

			 &lt;WOWOSwitch&gt;<xsl:value-of select="WOWOSwitch"/>&lt;/WOWOSwitch&gt;<br></br>

			 &lt;achtype_throttle_wowo&gt;<xsl:value-of select="achtype_throttle_wowo"/>&lt;/achtype_throttle_wowo&gt;<br></br>

			 &lt;ach_throttle_algorithm&gt;<xsl:value-of select="ach_throttle_algorithm"/>&lt;/ach_throttle_algorithm&gt;<br></br>

			 &lt;ach_throttle_backup_type&gt;<xsl:value-of select="ach_throttle_backup_type"/>&lt;/ach_throttle_backup_type&gt;<br></br>

&lt;/Entry&gt;

<br></br>

</xsl:for-each>

</xsl:for-each>

</xsl:template>

</xsl:stylesheet>

	<!--/xsl:when-->



<!--

<xsl:when test="transaction_type = 'A'  and ( not(transaction_subtype = '%') or not(flags = '%') or not(flags2 = '%') or not(flags3 = '%')) ">

	&lt;Entry&gt;<br></br>

			 &lt;transaction_type&gt;<xsl:value-of select="transaction_type"/>&lt;/transaction_type&gt;<br></br>

			 &lt;transaction_subtype&gt;<xsl:value-of select="transaction_subtype"/>&lt;/transaction_subtype&gt;<br></br>

			 &lt;flags&gt;<xsl:value-of select="flags"/>&lt;/flags&gt;<br></br>

			 &lt;flags2&gt;<xsl:value-of select="flags2"/>&lt;/flags2&gt;<br></br>

			 &lt;flags3&gt;<xsl:value-of select="flags3"/>&lt;/flags3&gt;<br></br>

			 &lt;transaction_country_code&gt;<xsl:value-of select="transaction_country_code"/>&lt;/transaction_country_code&gt;<br></br>

			 &lt;currency_code&gt;<xsl:value-of select="currency_code"/>&lt;/currency_code&gt;<br></br>

			 &lt;user_country_or_region&gt;<xsl:value-of select="user_country_or_region"/>&lt;/user_country_or_region&gt;<br></br>

			 &lt;seller_country&gt;<xsl:value-of select="seller_country"/>&lt;/seller_country&gt;<br></br>

			 &lt;ach_flags&gt;<xsl:value-of select="ach_flags"/>&lt;/ach_flags&gt;<br></br>

			 &lt;bank_name&gt;<xsl:value-of select="bank_name"/>&lt;/bank_name&gt;<br></br>

			 &lt;bank_capability&gt;<xsl:value-of select="bank_capability"/>&lt;/bank_capability&gt;<br></br>

			 &lt;transaction_attempt&gt;<xsl:value-of select="transaction_attempt"/>&lt;/transaction_attempt&gt;<br></br>

			 &lt;ach_type&gt;<xsl:value-of select="ach_type"/>&lt;/ach_type&gt;<br></br>

			 &lt;ach_backup_type&gt;<xsl:value-of select="ach_backup_type"/>&lt;/ach_backup_type&gt;<br></br>

			 &lt;WOWOSwitch&gt;<xsl:value-of select="WOWOSwitch"/>&lt;/WOWOSwitch&gt;<br></br>

			 &lt;achtype_throttle_wowo&gt;<xsl:value-of select="achtype_throttle_wowo"/>&lt;/achtype_throttle_wowo&gt;<br></br>

			 &lt;ach_throttle_algorithm&gt;<xsl:value-of select="ach_throttle_algorithm"/>&lt;/ach_throttle_algorithm&gt;<br></br>

			 &lt;ach_throttle_backup_type&gt;<xsl:value-of select="ach_throttle_backup_type"/>&lt;/ach_throttle_backup_type&gt;<br></br>

&lt;/Entry&gt;

<br></br>

	</xsl:when>



<xsl:when test="transaction_type = 'H' and transaction_subtype = 'L'">

	&lt;Entry&gt;<br></br>

			 &lt;transaction_type&gt;5&lt;/transaction_type&gt;<br></br>

			 &lt;transaction_country_code&gt;<xsl:value-of select="transaction_country_code"/>&lt;/transaction_country_code&gt;<br></br>

			 &lt;currency_code&gt;<xsl:value-of select="currency_code"/>&lt;/currency_code&gt;<br></br>

			 &lt;user_country_or_region&gt;<xsl:value-of select="user_country_or_region"/>&lt;/user_country_or_region&gt;<br></br>

			 &lt;seller_country&gt;<xsl:value-of select="seller_country"/>&lt;/seller_country&gt;<br></br>

			 &lt;ach_flags&gt;<xsl:value-of select="ach_flags"/>&lt;/ach_flags&gt;<br></br>

			 &lt;bank_name&gt;<xsl:value-of select="bank_name"/>&lt;/bank_name&gt;<br></br>

			 &lt;ach_type&gt;<xsl:value-of select="ach_type"/>&lt;/ach_type&gt;<br></br>

			 &lt;ach_backup_type&gt;<xsl:value-of select="ach_backup_type"/>&lt;/ach_backup_type&gt;<br></br>

			 &lt;WOWOSwitch&gt;<xsl:value-of select="WOWOSwitch"/>&lt;/WOWOSwitch&gt;<br></br>

			 &lt;achtype_throttle_wowo&gt;<xsl:value-of select="achtype_throttle_wowo"/>&lt;/achtype_throttle_wowo&gt;<br></br>

			 &lt;ach_throttle_algorithm&gt;<xsl:value-of select="ach_throttle_algorithm"/>&lt;/ach_throttle_algorithm&gt;<br></br>

			 &lt;ach_throttle_backup_type&gt;<xsl:value-of select="ach_throttle_backup_type"/>&lt;/ach_throttle_backup_type&gt;<br></br>

&lt;/Entry&gt;

<br></br>

	</xsl:when>





	<xsl:when test="transaction_type = 'H' and flags = 33554432 and flags3 = 32">

	&lt;Entry&gt;<br></br>

			 &lt;transaction_type&gt;1&lt;/transaction_type&gt;<br></br>

			 &lt;transaction_country_code&gt;<xsl:value-of select="transaction_country_code"/>&lt;/transaction_country_code&gt;<br></br>

			 &lt;currency_code&gt;<xsl:value-of select="currency_code"/>&lt;/currency_code&gt;<br></br>

			 &lt;user_country_or_region&gt;<xsl:value-of select="user_country_or_region"/>&lt;/user_country_or_region&gt;<br></br>

			 &lt;seller_country&gt;<xsl:value-of select="seller_country"/>&lt;/seller_country&gt;<br></br>

			 &lt;ach_flags&gt;<xsl:value-of select="ach_flags"/>&lt;/ach_flags&gt;<br></br>

			 &lt;bank_name&gt;<xsl:value-of select="bank_name"/>&lt;/bank_name&gt;<br></br>

			 &lt;ach_type&gt;<xsl:value-of select="ach_type"/>&lt;/ach_type&gt;<br></br>

			 &lt;ach_backup_type&gt;<xsl:value-of select="ach_backup_type"/>&lt;/ach_backup_type&gt;<br></br>

			 &lt;WOWOSwitch&gt;<xsl:value-of select="WOWOSwitch"/>&lt;/WOWOSwitch&gt;<br></br>

			 &lt;achtype_throttle_wowo&gt;<xsl:value-of select="achtype_throttle_wowo"/>&lt;/achtype_throttle_wowo&gt;<br></br>

			 &lt;ach_throttle_algorithm&gt;<xsl:value-of select="ach_throttle_algorithm"/>&lt;/ach_throttle_algorithm&gt;<br></br>

			 &lt;ach_throttle_backup_type&gt;<xsl:value-of select="ach_throttle_backup_type"/>&lt;/ach_throttle_backup_type&gt;<br></br>

&lt;/Entry&gt;

<br></br>

	</xsl:when>

<xsl:when test="transaction_type = 'H' and flags = 33554432 and flags2 = 2048">

	&lt;Entry&gt;<br></br>

			 &lt;transaction_type&gt;2&lt;/transaction_type&gt;<br></br>

			 &lt;transaction_country_code&gt;<xsl:value-of select="transaction_country_code"/>&lt;/transaction_country_code&gt;<br></br>

			 &lt;currency_code&gt;<xsl:value-of select="currency_code"/>&lt;/currency_code&gt;<br></br>

			 &lt;user_country_or_region&gt;<xsl:value-of select="user_country_or_region"/>&lt;/user_country_or_region&gt;<br></br>

			 &lt;seller_country&gt;<xsl:value-of select="seller_country"/>&lt;/seller_country&gt;<br></br>

			 &lt;ach_flags&gt;<xsl:value-of select="ach_flags"/>&lt;/ach_flags&gt;<br></br>

			 &lt;bank_name&gt;<xsl:value-of select="bank_name"/>&lt;/bank_name&gt;<br></br>

			 &lt;ach_type&gt;<xsl:value-of select="ach_type"/>&lt;/ach_type&gt;<br></br>

			 &lt;ach_backup_type&gt;<xsl:value-of select="ach_backup_type"/>&lt;/ach_backup_type&gt;<br></br>

			 &lt;WOWOSwitch&gt;<xsl:value-of select="WOWOSwitch"/>&lt;/WOWOSwitch&gt;<br></br>

			 &lt;achtype_throttle_wowo&gt;<xsl:value-of select="achtype_throttle_wowo"/>&lt;/achtype_throttle_wowo&gt;<br></br>

			 &lt;ach_throttle_algorithm&gt;<xsl:value-of select="ach_throttle_algorithm"/>&lt;/ach_throttle_algorithm&gt;<br></br>

			 &lt;ach_throttle_backup_type&gt;<xsl:value-of select="ach_throttle_backup_type"/>&lt;/ach_throttle_backup_type&gt;<br></br>

&lt;/Entry&gt;

<br></br>

	</xsl:when>

<xsl:when test="transaction_type = 'H' and flags = 67108864">

	&lt;Entry&gt;<br></br>

			 &lt;transaction_type&gt;3&lt;/transaction_type&gt;<br></br>

			 &lt;transaction_country_code&gt;<xsl:value-of select="transaction_country_code"/>&lt;/transaction_country_code&gt;<br></br>

			 &lt;currency_code&gt;<xsl:value-of select="currency_code"/>&lt;/currency_code&gt;<br></br>

			 &lt;user_country_or_region&gt;<xsl:value-of select="user_country_or_region"/>&lt;/user_country_or_region&gt;<br></br>

			 &lt;seller_country&gt;<xsl:value-of select="seller_country"/>&lt;/seller_country&gt;<br></br>

			 &lt;ach_flags&gt;<xsl:value-of select="ach_flags"/>&lt;/ach_flags&gt;<br></br>

			 &lt;bank_name&gt;<xsl:value-of select="bank_name"/>&lt;/bank_name&gt;<br></br>

			 &lt;ach_type&gt;<xsl:value-of select="ach_type"/>&lt;/ach_type&gt;<br></br>

			 &lt;ach_backup_type&gt;<xsl:value-of select="ach_backup_type"/>&lt;/ach_backup_type&gt;<br></br>

			 &lt;WOWOSwitch&gt;<xsl:value-of select="WOWOSwitch"/>&lt;/WOWOSwitch&gt;<br></br>

			 &lt;achtype_throttle_wowo&gt;<xsl:value-of select="achtype_throttle_wowo"/>&lt;/achtype_throttle_wowo&gt;<br></br>

			 &lt;ach_throttle_algorithm&gt;<xsl:value-of select="ach_throttle_algorithm"/>&lt;/ach_throttle_algorithm&gt;<br></br>

			 &lt;ach_throttle_backup_type&gt;<xsl:value-of select="ach_throttle_backup_type"/>&lt;/ach_throttle_backup_type&gt;<br></br>

&lt;/Entry&gt;

<br></br>

	</xsl:when>



<xsl:when test="transaction_type = 'H' and transaction_subtype = 'L'">

	&lt;Entry&gt;<br></br>

			 &lt;transaction_type&gt;5&lt;/transaction_type&gt;<br></br>

			 &lt;transaction_country_code&gt;<xsl:value-of select="transaction_country_code"/>&lt;/transaction_country_code&gt;<br></br>

			 &lt;currency_code&gt;<xsl:value-of select="currency_code"/>&lt;/currency_code&gt;<br></br>

			 &lt;user_country_or_region&gt;<xsl:value-of select="user_country_or_region"/>&lt;/user_country_or_region&gt;<br></br>

			 &lt;seller_country&gt;<xsl:value-of select="seller_country"/>&lt;/seller_country&gt;<br></br>

			 &lt;ach_flags&gt;<xsl:value-of select="ach_flags"/>&lt;/ach_flags&gt;<br></br>

			 &lt;bank_name&gt;<xsl:value-of select="bank_name"/>&lt;/bank_name&gt;<br></br>

			 &lt;ach_type&gt;<xsl:value-of select="ach_type"/>&lt;/ach_type&gt;<br></br>

			 &lt;ach_backup_type&gt;<xsl:value-of select="ach_backup_type"/>&lt;/ach_backup_type&gt;<br></br>

			 &lt;WOWOSwitch&gt;<xsl:value-of select="WOWOSwitch"/>&lt;/WOWOSwitch&gt;<br></br>

			 &lt;achtype_throttle_wowo&gt;<xsl:value-of select="achtype_throttle_wowo"/>&lt;/achtype_throttle_wowo&gt;<br></br>

			 &lt;ach_throttle_algorithm&gt;<xsl:value-of select="ach_throttle_algorithm"/>&lt;/ach_throttle_algorithm&gt;<br></br>

			 &lt;ach_throttle_backup_type&gt;<xsl:value-of select="ach_throttle_backup_type"/>&lt;/ach_throttle_backup_type&gt;<br></br>

&lt;/Entry&gt;

<br></br>

	</xsl:when>



<xsl:when test="transaction_type = 'H'">

	&lt;Entry&gt;<br></br>

			 &lt;transaction_type&gt;4&lt;/transaction_type&gt;<br></br>

			 &lt;transaction_country_code&gt;<xsl:value-of select="transaction_country_code"/>&lt;/transaction_country_code&gt;<br></br>

			 &lt;currency_code&gt;<xsl:value-of select="currency_code"/>&lt;/currency_code&gt;<br></br>

			 &lt;user_country_or_region&gt;<xsl:value-of select="user_country_or_region"/>&lt;/user_country_or_region&gt;<br></br>

			 &lt;seller_country&gt;<xsl:value-of select="seller_country"/>&lt;/seller_country&gt;<br></br>

			 &lt;ach_flags&gt;<xsl:value-of select="ach_flags"/>&lt;/ach_flags&gt;<br></br>

			 &lt;bank_name&gt;<xsl:value-of select="bank_name"/>&lt;/bank_name&gt;<br></br>

			 &lt;ach_type&gt;<xsl:value-of select="ach_type"/>&lt;/ach_type&gt;<br></br>

			 &lt;ach_backup_type&gt;<xsl:value-of select="ach_backup_type"/>&lt;/ach_backup_type&gt;<br></br>

			 &lt;WOWOSwitch&gt;<xsl:value-of select="WOWOSwitch"/>&lt;/WOWOSwitch&gt;<br></br>

			 &lt;achtype_throttle_wowo&gt;<xsl:value-of select="achtype_throttle_wowo"/>&lt;/achtype_throttle_wowo&gt;<br></br>

			 &lt;ach_throttle_algorithm&gt;<xsl:value-of select="ach_throttle_algorithm"/>&lt;/ach_throttle_algorithm&gt;<br></br>

			 &lt;ach_throttle_backup_type&gt;<xsl:value-of select="ach_throttle_backup_type"/>&lt;/ach_throttle_backup_type&gt;<br></br>

&lt;/Entry&gt;

<br></br>

	</xsl:when> -->

<!--/xsl:choose-->

<!--/xsl:for-each-->

	<!--/xsl:template-->

<!--/xsl:stylesheet-->


