import { Component, OnInit, Inject } from '@angular/core';
import { MatDialog, MatDialogRef } from '@angular/material/dialog';
import { UserService, common_response } from '../../interface/user.service';

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
  constructor(public dialogRef: MatDialogRef<NavUserDialog>, private userService: UserService) { }
  username = ''
  passwd = ''

  onSignInClick(): void {
    console.log('on sign in log: ' + this.username + ', ' + this.passwd);

    this.userService.registerUser('123', '123').subscribe((data: common_response) => {
      console.log('response: ' + data['errorCode'] + ', ' + data['msg']);
    });

  }

  onSignUpClick(): void {
    console.log('on sign up log' + this.username + ', ' + this.passwd);

    this.userService.loginUser('123', '123').subscribe((data: common_response) => {
      console.log('response: ' + data['errorCode'] + ', ' + data['msg']);
    });
    
  }
}
