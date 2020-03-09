import { Component, OnInit, Inject } from '@angular/core';
import { MatDialog, MatDialogRef, MAT_DIALOG_DATA } from '@angular/material/dialog';

export interface DialogData {
  animal: string;
  name: string;
}

@Component({
  selector: 'app-navigate',
  templateUrl: './navigate.component.html',
  styleUrls: ['./navigate.component.css']
})

export class NavigateComponent implements OnInit {

  constructor(public userDialog: MatDialog) { }

  ngOnInit() {
  }

  SignInOrUp(): void {
    const dialogRef = this.userDialog.open(NavUserDialog, {
      width: '250px'
    });

    dialogRef.afterClosed().subscribe(result => {
      console.log('closed');
    });

  }
}

@Component({
  selector: 'app-navigate-user-login',
  templateUrl: './user.dialog.html',
  styleUrls: ['./user.dialog.css']
})

export class NavUserDialog {
  constructor(public dialogRef: MatDialogRef<NavUserDialog>) { }

  onNoClick(): void {
    this.dialogRef.close();
  }
}
