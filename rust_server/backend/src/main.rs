// Author: hanvskun@hotmail.com

#![deny(warnings)]

use hyper::service::{make_service_fn, service_fn};
use hyper::{Body, Method, Request, Response, Server, StatusCode};
use backend::google_user::get_google_user_info;
use backend::channels::get_all_channels;


// router for v1 interface
//  - api/v1/user
//  - api/v1/channel
async fn router_v1(req: Request<Body>) -> Result<Response<Body>, hyper::Error> {
    match (req.method(), req.uri().path()) {
        (&Method::GET, "/api/v1/user") => {
            let id = get_google_user_info();

            Ok(Response::new(Body::from(format!("id={}", id))))
        }
        (&Method::GET, "/api/v1/channel") => {
            let id = get_all_channels();
            Ok(Response::new(Body::from(format!("get all channels, id={}", id))))
        }
        // Return the 404 Not Found for other routes.
        _ => {
            let mut not_found = Response::default();
            *not_found.status_mut() = StatusCode::NOT_FOUND;
            Ok(not_found)
        }
    }
}

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error + Send + Sync>> {
    let adder = ([127, 0, 0, 1], 3000).into();

    let service = make_service_fn(|_| async { Ok::<_, hyper::Error>(service_fn(router_v1)) });

    let server = Server::bind(&adder).serve(service);

    println!("Listening on http://{}", adder);

    server.await?;

    Ok(())
}
