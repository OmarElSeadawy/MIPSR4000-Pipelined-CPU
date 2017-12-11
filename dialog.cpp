#include "dialog.h"
#include "ui_dialog.h"
#include <QVarLengthArray>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include<iostream>
#include"Processor.h"
#include "RegFile.h"
#include "Dmem.hpp"


using namespace std;


int once_row = 0;
int once_cycles = 0;
Processor p;
int *RegValues = new int[32];
int *MemValues = new int[32];

QVector<QVector<QString>> vectorOfVectors;
vector<vector<QString>> stages;
vector<vector<QString>> btb;
vector<QString> procedureStack;



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)

{
    ui->setupUi(this);
    
    p.loadprogram("/Users/asserhangal/Qt Projects/TableView/testcase_st.txt");
    

    for(int i = 0; i<16; i++)
    {
        vector<QString> row;
        int x=0;

        for (int j=0; j<16; j++)
        {

            row.push_back(" ");
        }
        stages.push_back(row);
    }


//    for(int i = 0; i<16; i++)
//    {
//        vector<QString> row;
//        int x=0;
//
//        for (int j=0; j<16; j++)
//        {
//
//            row.push_back(" ");
//        }
//        btb.push_back(row);
//    }


}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked() //Reading from File
{
    int line_num = 0;

    QFile file ("/Users/asserhangal/Qt Projects/TableView/testcase_st.txt");

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "File not open!");

    }

    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString text = in.readLine();
        ui->plainTextEdit->appendPlainText(QString::number(line_num++) + "   " + text + "\n");

    }

    file.close();

}




void Dialog::on_run_once_clicked()
{
    
 
   // p.waitUntilSignalIsEmitted(run_once, SIGNAL(clicked()));
    cycles = new QStandardItemModel(30, 30, this);
    model_reg = new QStandardItemModel(32, 1, this);
    model_mem = new QStandardItemModel(32, 1, this);
    branch = new QStandardItemModel(16, 3, this);
      procedures = new QStandardItemModel(3,1,this);
    
    for (int i=0; i<32; ++i)
    {
        RegValues[i] = 0;
        MemValues[i] = 0;
    }
    
    p.execute(true, once_cycles);
    p.get_cycle(once_cycles);
    //once_cycles++;
    
    
    p.getMems(MemValues);
    p.getRegs(RegValues);
    

    p.setStages(stages);
    p.setBTB(btb);
    
    p.getStack(procedureStack);

    
    
    for (int row=0; row<stages.size(); ++row)
    {
        for(int col=0; col < stages[row].size(); ++col)
        {
            
            QModelIndex index_c = cycles->index(col, row, QModelIndex());
            cycles->setData(index_c, stages[row][col]);
            //cout<<stages[row][col].toStdString()<<endl;
        }
        
    }
    
    for(int i=0; i<btb.size(); i++)
        for(int j=0; j<btb[i].size(); j++)
        {
            QModelIndex index_btb = branch->index(i,j,QModelIndex());
            branch->setData(index_btb, btb[i][j]);
            
            
        }
    
    for (int row=0; row<31; row++)
    {
        QModelIndex index = model_reg->index(row, 0, QModelIndex());
        QModelIndex index2 = model_mem->index(row, 0, QModelIndex());
        
        
        model_reg->setData(index, RegValues[row+1]);
        model_mem->setData(index2, MemValues[row+1]);
    }
    
    for(int i=0; i<procedureStack.size(); i++)
    {
        QModelIndex index_proc = procedures->index(i,0,QModelIndex());
        procedures->setData(index_proc, procedureStack[i]);
        
    }
    
    ui->stack->setModel(procedures);
    ui->tableView2->setModel(cycles);
    ui->BTB_2->setModel(branch);
    ui->regFile->setModel(model_reg); //Display Reg Table
    ui->Dmem->setModel(model_mem); //Display Mem Table
    
    btb.clear();
    procedureStack.clear();
}

void Dialog::on_run_all_clicked()
{
    cycles = new QStandardItemModel(30, 30, this);
    model_reg = new QStandardItemModel(32, 1, this);
    model_mem = new QStandardItemModel(32, 1, this);
    branch = new QStandardItemModel(16, 3, this);
    procedures = new QStandardItemModel(3,1,this);
    
    
    for (int i=0; i<32; ++i)
    {
        RegValues[i] = 0;
        MemValues[i] = 0;
    }
    
    
    p.execute(false, once_cycles);
    
    p.getMems(MemValues);
    p.getRegs(RegValues);
    
    p.setStages(stages);
    p.setBTB(btb);
    //p.getStack(procedureStack);
    //n-=1;


    for (int row=0; row<stages.size(); ++row)
    {
         for(int col=0; col < stages[row].size(); ++col)
        {
           
                QModelIndex index_c = cycles->index(col, row, QModelIndex());
                cycles->setData(index_c, stages[row][col]);
                //cout<<stages[row][col].toStdString()<<endl;
         }

    }

    for(int i=0; i<btb.size(); i++)
        for(int j=0; j<btb[i].size(); j++)
        {
            QModelIndex index_btb = branch->index(i,j,QModelIndex());
            branch->setData(index_btb, btb[i][j]);
        }
    
    for (int row=0; row<31; row++)
    {
        QModelIndex index = model_reg->index(row, 0, QModelIndex());
        QModelIndex index2 = model_mem->index(row, 0, QModelIndex());
        
        
        model_reg->setData(index, RegValues[row+1]);
        model_mem->setData(index2, MemValues[row+1]);
    }

    ui->tableView2->setModel(cycles);
    ui->BTB_2->setModel(branch);
    ui->regFile->setModel(model_reg); //Display Reg Table
    ui->Dmem->setModel(model_mem); //Display Mem Table
}
