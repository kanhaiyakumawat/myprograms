<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="2.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:xs="http://www.w3.org/2001/XMLSchema" xmlns:fn="http://www.w3.org/2005/xpath-functions">

	<xsl:output method="xml" version="1.0" encoding="UTF-8" indent="yes"/>

	<xsl:template match="/">

	<BankTransactionTypes>

		<xsl:for-each-group select="document('achtype_mapping.xml')/Lookup/Data/Entry" group-by="concat(transaction_type, '|',transaction_subtype,'|',flags,'|',flags2,'|',flags3)">

			<Item>

				<transaction_type>

					<xsl:value-of select="transaction_type"/>

				</transaction_type>

				<transaction_subtype>

					<xsl:value-of select="transaction_subtype"/>

				</transaction_subtype>

				<flags>

					<xsl:value-of select="flags"/>

				</flags>

				<flags2>

					<xsl:value-of select="flags2"/>

				</flags2>

				<flags3>

					<xsl:value-of select="flags3"/>

				</flags3>

			</Item>

		</xsl:for-each-group>

			</BankTransactionTypes>

	</xsl:template>



</xsl:stylesheet>


