#include <stdio.h>
int oldtax = 0, newtax = 0, calcMoney = 0, taxableIncome, newtaxableincome;
int oldRegime(int taxableIncome)
{
    if(taxableIncome > 0)
        oldtax = 0;
        calcMoney = 250000;
    if(taxableIncome > 250000)
    {
        if((taxableIncome - calcMoney) > 250000)
            {
                oldtax += 0.05*250000;
                calcMoney = 500000;
            }
        else
            {
                oldtax += 0.05*(taxableIncome - 250000);
                calcMoney = taxableIncome;
            }
    }
    if(taxableIncome > 500000)
    {
        if((taxableIncome - calcMoney) > 500000)
            {
                oldtax += 0.2*500000;
                calcMoney = 1000000;
            }
        else
            {
                oldtax += 0.2*(taxableIncome - 500000);
                calcMoney = taxableIncome;
            }
    }
    if(taxableIncome > 1000000)
    {
        oldtax += 0.3*(taxableIncome - 1000000);
        calcMoney = taxableIncome;
    }
    if(taxableIncome > 5000000 && taxableIncome <= 10000000)
        oldtax += 0.1*(oldtax);
    if(taxableIncome > 10000000 && taxableIncome <= 20000000)
        oldtax += 0.15*(oldtax);
    //rebates
    if(taxableIncome <= 500000)
        oldtax = 0;
    //cess
    oldtax += 0.04*(oldtax);
    return (oldtax);
}
int newRegime(int newtaxableincome)
{
    if(newtaxableincome > 0)
        newtax = 0;
    if(newtaxableincome > 250000)
    {
        if(newtaxableincome > 500000)
            newtax += 12500;
        else
            newtax += 0.05*(newtaxableincome - 250000);
    }
    if(newtaxableincome > 500000)
    {
        if(newtaxableincome > 750000)
            newtax += 25000;
        else
            newtax += 0.1*(newtaxableincome - 500000);
    }
    if(newtaxableincome > 750000)
    {
        if(newtaxableincome > 1000000)
            newtax += 37500;
        else
            newtax += 0.15*(newtaxableincome - 750000);
    }
    if(newtaxableincome > 1000000)
    {
        if(newtaxableincome > 1250000)
            newtax += 50000;
        else
            newtax += 0.2*(newtaxableincome - 1000000);
    }
    if(newtaxableincome > 1250000)
    {
        if(newtaxableincome > 1500000)
            newtax += 62500;
        else
            newtax += 0.25*(newtaxableincome - 1250000);
    }
    if(newtaxableincome > 1500000)
        newtax += 0.3*(newtaxableincome - 1500000);
    if(newtaxableincome > 5000000 && newtaxableincome <= 10000000)
        newtax += 0.1*(newtax);
    if(newtaxableincome > 10000000 && newtaxableincome <= 20000000)
        newtax += 0.15*(newtax);
    if(newtaxableincome > 20000000 && newtaxableincome <= 50000000)
        newtax += 0.25*(newtax);
    if(newtaxableincome > 50000000)
        newtax += 0.37*(newtax);
    //rebates
    if(newtaxableincome <= 500000)
        newtax = 0;
    //cess
    newtax += 0.04*(newtax);
    return (newtax);
}
int main()
{
    int ags, hra, lta, rentincome, interestgains, capitalgains, medic, house, education, elss, nss, nps, ss, homeloan;
    printf("\n\t\t\t***INCOME TAX CALCULATOR***\n");
    printf("\nHEY!! I'm V!!!\n");
    printf("\nHere's how you can pay less tax legally :)\n");
    printf("\nLet's calculate your total income tax via both the old and new regimes\n");
    printf("\nEnter 0 if you are not an eligible recipient of that particular source of income\n");
    printf("\nEnter the required details asked to find out your Total Payable Income Tax :-\n");
    printf("\n--> Annual Gross Salary (in LPA): Rs ");
    scanf("%d", &ags);
    //EXEMPTIONS
    printf("\n--> House Rent Allowance: Rs ");
    scanf("%d", &hra);
    printf("\n--> Leave and Travel Allowance: Rs ");
    scanf("%d", &lta);
    printf("\n--> Standard Deductions: Rs 50,000 (for FY 2020-21)\n");
    taxableIncome = ags - hra - lta - 50000;
    //OTHER SOURCES
    printf("\nIncome From Other Sources:-\n");
    printf("\n--> Rental Income: Rs ");
    scanf("%d", &rentincome);
    printf("\n--> Income due to interest gains: Rs ");
    scanf("%d", &interestgains);
    printf("\n--> Income due to capital gains: Rs ");
    scanf("%d", &capitalgains);
    taxableIncome += (rentincome + interestgains + capitalgains);
    //DEDUCTIONS
    printf("\n--> Medical Insurance Premium: Rs ");
    scanf("%d", &medic);
    printf("\n--> House Insurance Premium: Rs ");
    scanf("%d", &house);
    printf("\n--> Education Insurance Premium: Rs ");
    scanf("%d", &education);
    printf("\n--> ELSS and PPF Investments: Rs ");
    scanf("%d", &elss);
    printf("\n--> National Savings Scheme Investments: Rs ");
    scanf("%d", &nss);
    printf("\n--> National Pension Scheme Investments: Rs ");
    scanf("%d", &nps);
    printf("\n--> Sukanya Samriddhi Investment: Rs ");
    scanf("%d", &ss);
    printf("\n--> Home Loans: Rs ");
    scanf("%d", &homeloan);
    taxableIncome -= (medic + house + education + elss + nss + nps + ss + homeloan);
    printf("\nYour Net Taxable Income according to OLD regime is Rs %d\n", taxableIncome);
    newtaxableincome = ags + rentincome + interestgains + capitalgains;
    printf("\nYour Net Taxable Income according to NEW regime is Rs %d\n", newtaxableincome);
    oldRegime(taxableIncome);
    printf("\nYour Total Payable Income Tax according to:-\n");
    printf("\n--> Old Regime : Rs %d\n", oldtax);
    newRegime(newtaxableincome);
    printf("\n--> New Regime : Rs %d\n", newtax);
    if(oldtax > newtax)
        printf("\nIt is beneficial for you to choose the NEW REGIME to save Rs %d\n", oldtax - newtax);
    else
        printf("\nIt is beneficial for you to choose the OLD REGIME to save Rs %d\n", newtax - oldtax);
    printf("\n\t\t\t***THANK YOU!***\n");
    return 0;
}
