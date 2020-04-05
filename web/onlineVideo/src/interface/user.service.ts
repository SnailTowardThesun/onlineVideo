import { Injectable } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http'
import { Observable } from 'rxjs'

import { ConfigService, OnlineVideoWebConfig } from '../config/config.service';

export interface common_response {
  errorCode: number;
  msg: string;
}

@Injectable({
  providedIn: 'root',
})
export class UserService {

  constructor(private http: HttpClient, private configService: ConfigService) { }


  registerUser(username: string | Blob, password: string | Blob): Observable<common_response> {
    console.log("interface: create user: " + this.configService.config['baseUrl']);


    let url = 'http://' + this.configService.config['baseUrl'] + '/auth/register'
    let u = new FormData();
    u.append('username', username);
    u.append('password', password)

    return this.http.post<common_response>(url, u);
  }

  loginUser(username: string | Blob, password: string | Blob): Observable<common_response> {
    console.log("interface: login user: " + this.configService.config['baseUrl']);

    let url = 'http://' + this.configService.config['baseUrl'] + '/auth/login'
    let u = new FormData();
    u.append('username', username);
    u.append('password', password);

    return this.http.post<common_response>(url, u);
  }

  identifyUser(): void {
    console.log("interface: identify user")

  }

  updateUser(): void {
    console.log("interface: update user")

  }

  deleteUser(): void {
    console.log("interface: delete user")
  }
}
